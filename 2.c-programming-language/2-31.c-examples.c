#include <stdio.h>
#include <math.h>


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

// 11.计算int, float, double和char字节大小
void example11_sizeof_operator()
{
	int integer_type;
	float float_type;
	double double_type;
	char char_type;

	long long_type;
	long long long_long_type;
	long double long_double_type;

	printf("int占用的字节数为：%ld\n", sizeof(integer_type));
	printf("float占用的字节数为：%ld\n", sizeof(float_type));
	printf("double占用的字节数为：%ld\n", sizeof(double_type));
	printf("char占用的字节数为：%ld\n", sizeof(char_type));

	printf("long占用的字节数为：%ld\n", sizeof(long_type));
	printf("long long占用的字节数为：%ld\n", sizeof(long_long_type));
	printf("long double占用的字节数为：%ld\n", sizeof(long_double_type));
}

// 12.交换两个数的值
void example12_swap()
{
	double a, b, temp;
	printf("请输入两个数字：");
	scanf("%lf %lf", &a, &b);

	printf("交换前：a = %.2lf, b = %.2lf\n", a, b);
	// 使用临时变量
	/*
	temp = a;
	a  = b;
	b = temp;
	*/
	// 不使用临时变量
	a = a + b;
	b = a - b;
	a = a - b;
	printf("交换后：a = %.2lf, b = %.2lf\n", a, b);
}

// 13.判断奇数/偶数
void example13_even_odd()
{
	int number;
	printf("请输入一个数字：");
	scanf("%d", &number);

	if (number & 1)
	{
		printf("%d是奇数\n", number);
	}
	else
	{
		printf("%d是偶数\n", number);
	}
}

// 14.循环区间范围内的奇数/偶数
void example14_for_even_odd()
{
	printf("[1, 10]中的偶数：");
	int i;
	for (i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			printf("%2d ", i);
		}
	}
	putchar('\n');

	printf("[1, 10]中的奇数：");
	for (i = 1; i <= 10; i++)
	{
		if (i % 2 != 0)
		{
			printf("%2d ", i);
		}
	}
	putchar('\n');
}

// 15.判断元音/辅音
void example15_vowel_consonant()
{
	char c;
	printf("请输入一个字母：");
	scanf("%c", &c);

	int is_lowercase_vowel = (c == 'a' || c== 'e' || c == 'i' || c == 'o' || c == 'u');
	int is_uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	if (is_lowercase_vowel || is_uppercase_vowel)
	{
		printf("%c是元音字母\n", c);
	} 
	else
	{
		printf("%c是辅音字母\n", c);
	}
}

// 16.判断三个数中的最大值
void example16_largest_number_three()
{
	double a, b, c;
	printf("请输入三个数字：");
	scanf("%lf %lf %lf", &a, &b, &c);

	if (a >= b && a >= c)
	{
		printf("%.2f 是最大数\n", a);
	}
	if (b >= a && b >= c)
	{
		printf("%.2f 是最大数\n", b);
	}
	if (c >= a && c >= b)
	{
		printf("%.2f 是最大数\n", c);
	}
}

// 17.一元二次方程
void example17_quadratic_roots()
{
	float a, b, c, x1, x2, delta;
	printf("请输入一元二次方程的三个系数：");
	scanf("%f %f %f", &a, &b, &c);

	if (a != 0)
	{
		delta = sqrt(b * b - 4 * a *c);
		x1 = (-b + delta) / (2 * a);
		x2 = (-b - delta) / (2 * a);
		if (x1 < x2)
		{
			printf("%.2f %.2f\n", x2, x1);
		}
		else 
		{
			printf("%.2f %.2f\n", x1, x2);
		}
	}
}

// 18.判断闰年
void example18_leap_year()
{
	int year;
	printf("请输入年份：");
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("%d 是闰年\n", year);
	}
	else 
	{
		printf("%d 不是闰年\n", year);
	}
}

// 19.判断正数/负数
void example19_negative_positive_zero()
{
	double number;
	printf("请输入一个数字：");
	scanf("%lf", &number);
	if (number == 0.0)
	{
		printf("%.2f 等于 0\n", number);
	}
	else if (number > 0)
	{
		printf("%,2f 是正数\n", number);
	}
	else 
	{
		printf("%.2f 是负数\n", number);
	}
}

// 20.判断字母
void example20_alphabet()
{
	char c;
	printf("请输入一个字符：");
	scanf("%c", &c);

	if ((c >= 'a' && c <= 'z') || (c >=  'A' && c <= 'Z'))
	{
		printf("%c 是字母\n", c);
	}
	else
	{
		printf("%c 不是字母\n", c);
	}
}

int main()
{
	#if 0
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
	#endif

	printf("--------%s--------\n", "11.计算int, float, double和char字节大小");
	example11_sizeof_operator();

	printf("--------%s--------\n", "12.交换两个数的值");
	example12_swap();

	printf("--------%s--------\n", "13.判断奇数/偶数");
	example13_even_odd();

	printf("--------%s--------\n", "14.循环区间范围内的奇数/偶数");
	example14_for_even_odd();

	// 处理换行符号
	getchar();
	printf("--------%s--------\n", "15.判断元音/辅音");
	example15_vowel_consonant();

	printf("--------%s--------\n", "16.判断三个数中的最大值");
	example16_largest_number_three();

	printf("--------%s--------\n", "17.一元二次方程");
	example17_quadratic_roots();

	printf("--------%s--------\n", "18.判断闰年");
	example18_leap_year();

	printf("--------%s--------\n", "19.判断正数/负数");
	example19_negative_positive_zero();

	// 处理换行符号
	getchar();
	printf("--------%s--------\n", "20.判断字母");
	example20_alphabet();
	return 0;
}

