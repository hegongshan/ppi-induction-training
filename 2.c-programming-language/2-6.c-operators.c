#include <stdio.h>

int main()
{
	// 1.算术运算
	printf("----1.算术运算----\n");
	int a = 21;
	int b = 10;
	int c;
	printf("a = %d, b = %d\n", a, b);

	c = a + b;
	printf("a + b = %d\n", c);
	c = a - b;
	printf("a - b = %d\n", c);
	c = a * b;
	printf("a * b = %d\n", c);
	c = a / b;
	printf("a / b = %d\n", c);
	c = a % b;
	printf("a % b = %d\n", c);
	c = a++;
	printf("c = a++ 等于 %d\n", c);
	c = a--;
	printf("c = a-- 等于 %d\n--------\n", c);

	// ++a与a++
	int d = 10;
	printf("d = %d, 先赋值后运算\n", d);
	int e = d ++;
	printf("e = d++ 等于 %d\n", e);
	printf("d = %d\n--------\n", d);
	
	d = 10;
	printf("d = %d\n", d);
	e = d --;
	printf("e = d-- 等于 %d\n", e);
	printf("d = %d\n--------\n", d);

	d = 10;
	printf("d = %d, 先运算后赋值\n", d);
	e = ++d;
	printf("e = ++d 等于 %d\n", e);
	printf("d = %d\n--------\n", d);

	d = 10;
	printf("d = %d\n", d);
	e = --d;
	printf("e = --d 等于 %d\n", e);
	printf("d = %d\n--------\n", d);


	// 2.关系运算
	printf("----2.关系运算----\n");
	a = 21;
	b = 10;
	printf("a = %d, b = %d\n", a, b);
	if (a == b) 
	{
		printf("a 等于 b\n");
	} 
	else 
	{
		printf("a 不等于 b\n");
	}

	if (a < b) 
	{
		printf("a 小于 b\n");
	} 
	else 
	{
		printf("a 不小于 b\n");
	}

	if (a > b)
	{
		printf("a 大于 b\n");
	}
	else
	{
		printf("a 不大于 b\n");
	}

	a = 5;
	b = 20;
	printf("a = %d, b = %d\n", a, b);
	if (a <= b) 
	{
		printf("a 小于等于 b\n");
	}
	if (b >= a)
	{
		printf("b 大于等于 a\n");
	}


	// 3.逻辑运算
	a = 5;
	b = 20;
	printf("a = %d, b = %d\n", a, b);
	if (a && b)
	{
		printf("a && b为真\n");
	}
	if (a || b)
	{
		printf("a || b为真\n");
	}

	a = 0;
	b = 10;
	printf("a = %d, b = %d\n", a, b);
	if (a && b)
	{
		printf("a && b为真\n");
	}
	else 
	{
		printf("a && b为假\n");
	}
	if (!(a && b))
	{
		printf("!(a && b)为真\n");
	}


	// 3.位运算
	printf("----3.位运算----\n");
	unsigned int a1 = 60;
	unsigned int b1 = 13;
	printf("a = %d, b = %d\n", a1, b1);
	c = a1 & b1;
	printf("a & b 为 %d\n", c);
	c = a1 | b1;
	printf("a | b 为 %d\n", c);
	c = a1 ^ b1;
	printf("a ^ b为 %d\n", c);
	c = ~a1;
	printf("~a 为 %d\n", c);
	c = a1 << 2;
	printf("a << 2 为 %d\n", c);
	c = a1 >> 2;
	printf("a >> 2 为 %d\n", c);


	// 4.赋值运算
	printf("----4.赋值运算----\n");
	a = 21;
	printf("a = %d\n", a);

	c = a;
	printf("c = a 为 %d\n", c);
	c += a;
	printf("c += a 为 %d\n", c);
	c -= a;
	printf("c -= a 为 %d\n", c);
	c *= a;
	printf("c *= a 为 %d\n", c);
	c /= a;
	printf("c /= a 为 %d\n", c);

	c = 200;
	printf("c = %d\n", c);
	c %= a;
	printf("c %= a 为 %d\n", c);
	c <<= 2;
	printf("c <<= 2 为 %d\n", c);
	c >>= 2;
	printf("c >>= 2 为 %d\n", c);
	c &= 2;
	printf("c &= 2 为 %d\n", c);
	c ^= 2;
	printf("c ^= 2 为 %d\n", c);
	c |= 2;
	printf("c |= 2 为 %d\n", c);


	// 5.杂项运算
	printf("----5.杂项运算----\n");
	a = 4;
	short b2;
	double c2;
	int * ptr;
	printf("int 占用的字节数为 %lu\n", sizeof(a));
	printf("short 占用的字节数为 %lu\n", sizeof(b2));
	printf("double 占用的字节数为 %lu\n", sizeof(c2));

	ptr = &a;
	printf("a = %d\n", a);
	printf("*ptr的值为 %d\n", *ptr);

	// 三目运算符
	a = 10;
	b = (a == 1) ? 20 : 30;
	printf("b = (a == 1) ? 20 : 30  的值是 %d\n", b);
	b = (a == 10) ? 20 : 30;
	printf("b  = (a == 10) ? 20 : 30 的值是 %d\n", b);


	// 6.运算符优先级
	printf("----6.运算符优先级----\n");
	a = 20;
	b = 10;
	c = 15;
	d = 5;
	printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
	int result = (a + b) * c / d;
	printf("(a + b) * c / d 的值为 %d\n", result);
	result = ((a + b) * c) / d;
	printf("((a + b) * c) / d 的值为 %d\n", result);
	result = (a + b) * (c / d);
	printf("(a + b) * (c / d) 的值为 %d\n", result);
	result = a + (b * c) / d;
	printf("a + (b * c) / d 的值为 %d\n", result);

	return 0;
}