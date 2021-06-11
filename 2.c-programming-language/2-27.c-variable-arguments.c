#include <stdio.h>
#include <stdarg.h>

double average(int num, ...)
{
	int i;
	double sum = 0.0;
	va_list valist;

	// 1.初始化
	va_start(valist, num);

	// 2.访问变量
	for (i = 0; i < num; i++) 
	{
		sum  += va_arg(valist, int);
	}

	// 3.释放内存
	va_end(valist);

	return sum / num;
}

int main()
{
	printf("1, 2, 4, 5, 8, 10的平均值为：\t%f\n", average(6, 1, 2, 4, 6, 8, 10));
	printf("5, 10, 15的平均值为：\t%f\n", average(3, 5, 10, 15));
	return 0;
}