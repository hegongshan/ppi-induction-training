#include <stdio.h>

// 函数声明
int max(int num1, int num2);

void swap_by_value(int x, int y);

void swap_by_reference(int * x, int * y);


int main()
{
	int a = 100;
	int b = 200;
	int result = max(a, b);
	printf("a = %d, b = %d, 最大者 = %d\n", a, b, result);
	

	printf("------1.传值调用------\n");
	printf("交换前，a的值： %d\n", a);
	printf("交换前，b的值： %d\n", b);
	swap_by_value(a, b);
	printf("交换后，a的值： %d\n", a);
	printf("交换后，b的值： %d\n", b);



	printf("------2.引用调用------\n");
	printf("交换前，a的值： %d\n", a);
	printf("交换前，b的值： %d\n", b);
	swap_by_reference(&a, &b);
	printf("交换后，a的值： %d\n", a);
	printf("交换后，b的值： %d\n", b);

	return 0;
}

int max(int num1, int num2)
{
	int result = num1 >= num2 ? num1 : num2;
}

void swap_by_value(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
	return ;
}

void swap_by_reference(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	return ;
}