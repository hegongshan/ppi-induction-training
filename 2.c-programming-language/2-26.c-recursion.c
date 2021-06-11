#include <stdio.h>

// 求x的阶乘
double factorial(unsigned int x)
{
	if (x <= 1) 
	{
		return 1;
	}
	return x * factorial(x - 1);
}

double fibonaci(int x)
{
	if (x == 0)
	{
		return 0;
	}
	if (x == 1)
	{
		return 1;
	}
	return fibonaci(x - 1) + fibonaci(x - 2);
}

double fibonaci_by_dp(int x)
{
	if (x == 0)
	{
		return 0;
	}
	if (x == 1)
	{
		return 1;
	}
	int a = 0, b = 1;
	int i;
	for (i = 2; i <= x; i++) {
		b = b + a;
		a = b - a;
	}
	return b;
}

int main()
{
	printf("--------1.阶乘--------\n");
	int x = 10;
	printf("%d的阶乘为：%f\n", x, factorial(x));


	printf("--------2.斐波那契数列\n");
	printf("递归\t动态规划\n");
	int i;
	for (i = 0; i <= 10; i++)
	{
		printf("%f %f\n", fibonaci(i), fibonaci_by_dp(i));
	}
	return 0;
}