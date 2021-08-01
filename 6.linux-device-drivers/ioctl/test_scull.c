#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "scull.h"

int main(int argc, char const *argv[])
{
	int fd;
	int quantum;
	char data[] = "Hello world!";
	char buf[2048];

	// 打开设备
	fd = open("/dev/scull", O_RDWR);
	if (fd == -1)
	{
		printf("scull: open failed, fd = %d\n", fd);
		return -1;
	}

	// 1.测试write和read
	printf("data = %s\n", data);
	write(fd, data, sizeof(data));

	read(fd, buf, sizeof(data));
	printf("data = %s\n", data);

	// 2.测试ioctl
	// 2.1测试清空
	ioctl(fd, SCULL_IOC_CLEAR);

	// 2.2传值测试
	quantum = ioctl(fd, SCULL_IOC_QUERY);
	printf("quantum = %d\n", quantum);
	quantum = 33;
	ioctl(fd, SCULL_IOC_TELL, quantum);

	// 2.3传指针测试
	ioctl(fd, SCULL_IOC_GET, &quantum);
	quantum = 66;
	ioctl(fd, SCULL_IOC_SET, &quantum);

	close(fd);
	return 0;
}
