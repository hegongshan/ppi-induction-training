#ifndef _SCULL_H_
#define _SCULL_H_

// 定义幻数
#define SCULL_IOC_MAGIC 'k'

#define SCULL_IOC_CLEAR _IO(SCULL_IOC_MAGIC, 0)

#define SCULL_IOC_GET _IOR(SCULL_IOC_MAGIC, 1, int)

#define SCULL_IOC_QUERY _IO(SCULL_IOC_MAGIC, 2)

#define SCULL_IOC_SET _IOW(SCULL_IOC_MAGIC, 3, int)

#define SCULL_IOC_TELL _IO(SCULL_IOC_MAGIC, 4)

#define SCULL_DEV_SIZE 2048

// 默认使用动态分配
#define SCULL_DEV_MAJOR 0
// ioctl的最大命令号
#define SCULL_IOC_MAXNR 4

struct scull_dev
{
	char *data;
	unsigned long size;
	int quantum;
	// struct cdev cdev; /*字符设备结构，定义在<linux/cdev.h>中*/
};

#endif