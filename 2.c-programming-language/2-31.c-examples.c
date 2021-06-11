#include <stdio.h>

// 1.输出hello world
void example1_printf_helloworld()
{
	printf("Hello world!\n");
}

// 2.输出整数
void example2_printf_int()
{
	int number;
	printf("请输入一个整数：\n");
	scanf("%d", &number);
	printf("输入的整数为：%d\n", number);
}

// 3.输出单个字符
void example3_printf_char()
{
	char c = 'c';
	printf("变量 c 的值为：%c\n", c);
}

// 4.输出浮点数
void example4_printf_float()
{
	float f = 3.141592;
	printf("变量 f 的值为%f\n", f);
}

// 5.输出双精度数
void example5_printf_double()
{
	double d = 3.141592654;
	printf("变量 d 的值为：%le\n", d);
}

// 6.两个数字相加
void example6_add_numbers()
{
	int a, b;
	printf("请输入两个数字\n");
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);
}

// 7.两个浮点数相乘
void example7_product_numbers()
{
	double a, b;
	printf("请输入两个浮点数；\n");
	scanf("%lf %lf", &a, &b);
	printf("%lf * %lf = %.2lf\n", a, b, a * b);
}

// 8.字符转ASCII码
void example8_char_to_ascii_value()
{
	char c;
	printf("请输入一个字符\n");
	scanf("%c", &c);
	printf("%c 的ASCII码值为 %d\n", c, c);
}

// 9.两数相除，如果有余数，输出余数
void example9_remainder_quotient()
{
	int dividend, divisor, quotient, remainder;

	printf("请输入被除数和除数：\n");
	scanf("%d %d", &dividend, &divisor);

	// 商
	quotient = dividend / divisor;
	// 余数
	remainder = dividend % divisor;
	printf("商 = %d, 余数 = %d\n", quotient, remainder);
}

// 10.数值比较
void example10_int_data_compare()
{
	int a, b;
	printf("请输入两个数字：\n");
	scanf("%d %d", &a, &b);
	if (a > b)
	{
		printf("%d > %d\n", a, b);
	}
	else 
	{
		printf("%d <= %d\n", a, b);
	}
}

int main()
{
	printf("--------1.输出hello world--------\n");
	example1_printf_helloworld();

	printf("--------2.输出整数--------\n");
	example2_printf_int();

	printf("------- 3.输出单个字符---------\n");
	example3_printf_char();

	printf("--------4.输出浮点数--------\n");
	example4_printf_float();

	printf("--------%s--------\n", "5.输出双精度数");
	example5_printf_double();

	printf("--------%s--------\n", "6.两个数字相加");
	example6_add_numbers();

	printf("--------%s--------\n", "7.两个浮点数相乘");
	example7_product_numbers();

	// 处理换行符
	getchar();
	printf("--------%s--------\n", "8.字符转ASCII码");
	example8_char_to_ascii_value();

	printf("--------%s--------\n", "9.两数相除，如果有余数，输出余数");
	example9_remainder_quotient();

	printf("--------%s--------\n", "10.数值比较");
	example10_int_data_compare();

}

