#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/mman.h>

int main(int argc, char const *argv[])
{
	int fd;
	char *content = "Hello world!";
	char *buf;
	char *mmap_buf;
	int len = 1024;

	fd = open("/dev/mmap_driver", O_RDWR);
	if (fd < 0)
	{
		printf("mmap: open failed, fd = %d\n", fd);
		return -1;
	}

	// 1.建立内存映射
	printf("mmap: start...\n");
	buf = (char *)malloc(len * sizeof(char));
	memset(buf, 0, len);
	mmap_buf = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	printf("mmap: end\n");

	// 2.测试读写数据
	printf("content = %s\n", content);
	// 写数据
	strcpy(mmap_buf, content);
	// 读数据
	memset(buf, 0, len);
	strcpy(buf, mmap_buf);
	printf("buf = %s\n", buf);
	assert(strcmp(content, buf) == 0);

	// 3.删除内存映射，释放申请的内存
	munmap(mmap_buf, len);
	free(buf);
	close(fd);

	return 0;
}