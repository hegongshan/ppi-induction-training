#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <asm/page.h>

#define MMAP_DEV_MAJOR 0
#define MM_SIZE 2048

static char module_name[] = "mmap_driver";
static int dev_major = MMAP_DEV_MAJOR;
struct cdev cdev;
struct class *mmap_class;

/**
 * 打开函数
 */
static int dev_open(struct inode *inode, struct file *filep)
{
	filep->private_data = kmalloc(MM_SIZE, GFP_KERNEL);
	printk(KERN_INFO "mmap: open successfully\n");
	return 0;
}

/**
 * 关闭函数
 */
static int dev_release(struct inode *inode, struct file *filep)
{
	if (filep)
	{
		kfree(filep->private_data);
	}
	printk(KERN_INFO "mmap: release successfully\n");
	return 0;
}

/**
 * 虚拟内存区域打开函数
 */
static void vma_open(struct vm_area_struct *vma)
{
	printk(KERN_NOTICE "VMA open, virt %lx, phys %lx\n", vma->vm_start, vma->vm_pgoff << PAGE_SHIFT);
}

/**
 * 虚拟内存区域关闭函数
 */
static void vma_close(struct vm_area_struct *vma)
{
	printk(KERN_NOTICE "VMA close.\n");
}

static struct vm_operations_struct vma_ops = {
	.open = vma_open,
	.close = vma_close,
};

/**
 * mmap实现
 * struct vm_area_struct 定义在<linux/mm.h>
 */
static int dev_mmap(struct file * filep, struct vm_area_struct *vma)
{
	if (remap_pfn_range(vma, 
									  vma->vm_start,
									  vma->vm_pgoff,
									  vma->vm_end - vma->vm_start,
									  vma->vm_page_prot))
	{
		return -EAGAIN;
	}
	vma->vm_ops = &vma_ops;
	vma_open(vma);
	return 0;
}

static struct file_operations dev_fops = {
	.owner = THIS_MODULE,
	.open = dev_open,
	.release = dev_release,
	.mmap = dev_mmap,
};

/*
 * 初始化函数
 */
static int __init dev_init(void)
{
	int result;
	// dev_t定义在<linux/tpes.h>中, MKDEV定义在<linux/kdev_t.h>
	dev_t devno = MKDEV(dev_major, 0);

	// 1.分配主设备号
	// 如果设置了主设备号
	if (dev_major)
	{
		// 静态分配设备编号
		result = register_chrdev_region(devno, 1, module_name);
	}
	else
	{
		// 动态分配设备编号
		result = alloc_chrdev_region(&devno, 0, 1, module_name);
		dev_major = MAJOR(devno);
	}

	if (result < 0)
	{
		printk(KERN_WARNING "mmap: can't get major %d\n", dev_major);
		return result;	
	}

	// 2.自动创建节点
	mmap_class = class_create(THIS_MODULE, module_name);
	device_create(mmap_class, NULL, devno, NULL, module_name);

	// 3.注册设备
	cdev_init(&cdev, &dev_fops);
	cdev.owner = THIS_MODULE;
	cdev.ops = &dev_fops;
	cdev_add(&cdev, devno, 1);

	printk("scull: init successfully\n");
	return 0;
}

/**
 * 退出函数
 */
static void __exit dev_exit(void)
{
	// 移除字符设备
	cdev_del(&cdev);
	// 删除节点
	device_destroy(mmap_class, MKDEV(dev_major, 0));
	class_destroy(mmap_class);

	unregister_chrdev_region(MKDEV(dev_major, 0), 1);
	printk(KERN_INFO "mmap: exit successfully\n");
}

MODULE_AUTHOR("hegongshan <hegongshan@qq.com>");
MODULE_LICENSE("GPL");

module_init(dev_init);
module_exit(dev_exit);
