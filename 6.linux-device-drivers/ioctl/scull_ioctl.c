#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/errno.h>
#include <linux/stat.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <asm/uaccess.h>

#include "scull.h"

static int scull_major = SCULL_DEV_MAJOR;
module_param(scull_major, int, S_IRUGO);

struct scull_dev *devp;
struct cdev cdev;
struct class *scull_class;

int scull_trim(struct scull_dev *dev)
{
	if (dev)
	{
		if (dev->data)
		{
			kfree(dev->data);
		}
		dev->data = NULL;
		dev->size = 0;
	}
	return 0;
}

/**
 * 打开
 */
int scull_open(struct inode *inode, struct file *filep)
{
	struct scull_dev *dev = devp;

	// container_of定义在<linux/kernel.h>中
	//dev = container_of(inode->i_cdev, struct scull_dev, cdev);
	filep->private_data = dev;

	printk(KERN_INFO "scull: open successfully\n");
	return 0;
}

/**
 * 释放
 */
int scull_release(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "scull: release successfully\n");
	return 0;
}

/**
 * 读取
 */
ssize_t scull_read(struct file *filep, char __user *buf, size_t count, loff_t *f_pos)
{
	struct scull_dev *dev = filep->private_data;
	ssize_t retval = 0;

	if (*f_pos >= dev->size)
	{
		return retval;
	}
	if (*f_pos + count > dev->size)
	{
		count = dev->size - *f_pos;
	}

	// 如果返回不为0，则发生了错误
	if (copy_to_user(buf, (void *)(dev->data + *f_pos), count))
	{
		retval = -EFAULT;
	}
	else 
	{
		*f_pos += count;
		retval = count;
		printk(KERN_INFO "scull: read successfully\n");
	}
	return retval;
}

/**
 * 写入
 */
ssize_t scull_write(struct file *filep, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct scull_dev *dev = filep->private_data;
	ssize_t retval = -ENOMEM;

	if (*f_pos + count > dev->size)
	{
		count = dev->size - *f_pos;
	}

	if (!dev->data)
	{
		dev->data = kmalloc(SCULL_DEV_SIZE, GFP_KERNEL);
		if (!dev->data)
		{
			return retval;
		}
		memset(dev->data, 0, SCULL_DEV_SIZE);
	}
	
	// 从用户空间写入数据
	if(copy_from_user(dev->data + *f_pos, buf, count))
	{
		retval = -EFAULT;
	}
	else
	{
		*f_pos += count;
		retval = count;
		printk(KERN_INFO "scull: write successfully\n");

		// 更新文件大小
		if (*f_pos > dev->size)
		{
			dev->size = *f_pos;
		}
	}
	return retval; 
}

/**
 * 实现ioctl
 */
long scull_ioctl(struct file *filep, unsigned int cmd, unsigned long args)
{
	int err = 0, retval = 0;
	struct scull_dev *dev =  filep->private_data;

	// 1.如果幻数不匹配
	if (_IOC_TYPE(cmd) != SCULL_IOC_MAGIC)
	{
		return -ENOTTY;
	}
	// 2.如果序数大于最大序数
	if (_IOC_NR(cmd) > SCULL_IOC_MAXNR)
	{
		return -ENOTTY;
	}
	// 3.判断数据传输的方向：读/写
	if (_IOC_DIR(cmd) && _IOC_READ)
	{
		err = !access_ok(VERIFY_WRITE, (void __user *)args, _IOC_SIZE(cmd));
	}
	else if (_IOC_DIR(cmd) && _IOC_WRITE)
	{
		err = !access_ok(VERIFY_READ, (void __user *)args, _IOC_SIZE(cmd));
	}
	if (err)
	{
		return -EFAULT;
	}

	// 4.根据命令号，匹配不同的处理操作
	switch(cmd)
	{
		case SCULL_IOC_CLEAR:
			dev->quantum = 0;
			break;
		case SCULL_IOC_GET:
			retval = __put_user(dev->quantum, (int __user *)args);
			printk(KERN_INFO "scull: SCUULL_IOC_GET quantum = %d\n", dev->quantum);
			break;
		case SCULL_IOC_QUERY:
			retval = dev->quantum;
			printk(KERN_INFO "scull: SCULL_IOC_QUERY quantum = %d\n", dev->quantum);
			break;
		case SCULL_IOC_SET:
			retval = __get_user(dev->quantum, (int __user *)args);
			printk(KERN_INFO "scull: SCULL_IOC_SET quantum = %d\n", dev->quantum);
			break;
		case SCULL_IOC_TELL:
			dev->quantum = args;
			printk(KERN_INFO "scull: SCULL_IOC_TELL quantum = %d\n", dev->quantum);
			break;
	}
	return retval;
}

/* struct file_operations定义在<linux/fs.h>中 */
struct file_operations scull_fops = {
	.owner = THIS_MODULE,
	.read = scull_read,
	.write = scull_write,
	.open = scull_open,
	.release = scull_release,
	.unlocked_ioctl = scull_ioctl,
};

/**
 * 初始化函数
 */
static int __init scull_init(void)
{
	int result;
	// dev_t定义在<linux/tpes.h>中, MKDEV定义在<linux/kdev_t.h>
	dev_t devno = MKDEV(scull_major, 0);

	// 1.分配主设备号
	// 如果设置了主设备号
	if (scull_major)
	{
		// 静态分配设备编号
		result = register_chrdev_region(devno, 1, "scull");
	}
	else
	{
		// 动态分配设备编号
		result = alloc_chrdev_region(&devno, 0, 1, "scull");
		scull_major = MAJOR(devno);
	}

	if (result < 0)
	{
		printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
		return result;	
	}

	// 2.自动创建节点
	scull_class = class_create(THIS_MODULE, "scull");
	device_create(scull_class, NULL, devno, NULL, "scull");

	// 3.注册设备
	cdev_init(&cdev, &scull_fops);
	cdev.owner = THIS_MODULE;
	cdev.ops = &scull_fops;
	cdev_add(&cdev, devno, 1);

	devp = kmalloc(sizeof(struct scull_dev), GFP_KERNEL);
	if (!devp)
	{
		return -ENOMEM;
	} 

	devp->size = SCULL_DEV_SIZE;
	devp->data = kmalloc(SCULL_DEV_SIZE, GFP_KERNEL);	
	if (!(devp->data))
	{
		return -ENOMEM;
	}
	memset(devp->data, 0, SCULL_DEV_SIZE);
	printk("scull: init successfully\n");
	return 0;
}

/**
 * 退出函数
 */
static void __exit scull_exit(void)
{
	scull_trim(devp);
	// 移除字符设备
	cdev_del(&cdev);
	kfree(devp);

	// 删除节点
	device_destroy(scull_class, MKDEV(scull_major, 0));
	class_destroy(scull_class);

	// 释放设备编号
	unregister_chrdev_region(MKDEV(scull_major, 0), 1);
	printk(KERN_INFO "scull: exit successfully.\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gongshan He <hegongshan@qq.com>");

module_init(scull_init);
module_exit(scull_exit);