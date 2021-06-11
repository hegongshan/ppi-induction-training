#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

extern int errno;

int main()
{
	printf("--------1.错误处理初体验--------\n");
	int errnum;
	FILE * pf = fopen("file_not_exists.txt", "rb");
	if (pf == NULL)
	{
		errnum = errno;
		fprintf(stderr, "错误号：%d\n", errnum);
		perror("使用perror打印错误信息");
		fprintf(stderr, "打开文件错误：%s\n", strerror(errnum));
	}


	printf("--------2.被除零错误--------\n");
	int dividend = 20;
	int divisor = 0;
	int quotient;

	if (divisor == 0)
	{
		fprintf(stderr, "除数为0\n");
		// exit(-1);
		exit(EXIT_FAILURE);
	}


	printf("--------3.程序退出状态--------\n");
	divisor = 4;
	quotient = dividend / divisor;
	fprintf(stderr, "商 = %d\n", quotient);
	// exit(0);
	exit(EXIT_SUCCESS);
}