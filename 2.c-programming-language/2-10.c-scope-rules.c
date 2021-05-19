#include <stdio.h>

int g;


int main()
{
	int a, b;
	int c;

	a = 10;
	b = 20;
	c = a + b;
	printf("--------1.局部变量--------\n");
	printf("a = %d, b = %d, c = a + b = %d\n", a, b, c);


	g  = a + b;
	printf("--------2.全局变量--------\n");
	printf("a = %d, b = %d, g = a + b = %d\n", a, b, g);


	// 测试全局变量和局部变量重名的情况
	printf("--------3.测试全局变量和局部变量重名的情况--------\n");
	int g = 10;
	printf("g = %d\n", g);


	printf("--------4.形式参数------\n");
	a = 10;
	b = 20;
	c = 0;
	int sum(int, int);

	printf("main函数中a = %d\n", a);
	printf("main函数中b = %d\n", b);
	c = sum(a, b);
	printf("main函数中c = %d\n", c);
}

int sum(int a, int b)
{
	printf("sum函数中a = %d\n", a);
	printf("sum函数中b = %d\n", b);
	return a + b;
}