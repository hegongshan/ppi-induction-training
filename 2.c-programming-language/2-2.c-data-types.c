#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() 
{
	printf("int类型的存储大小为：%lu\n", sizeof(int));
	printf("float类型占用的字节数为：%lu\n", sizeof(float));
	printf("float 最小值：%E\n", FLT_MIN);
	printf("float 最大值：%E\n", FLT_MAX);
	// FLoaT DIGits
	printf("float 精度：%d\n", FLT_DIG);
	return 0;
}