#include <stdio.h>
#include <string.h>

struct
{
	unsigned int widthValidated;
	unsigned int heightValidated;
} status1;

struct
{
	unsigned int widthValidated : 1;
	unsigned int heightValidated : 1;
} status2;

struct
{
	unsigned int age : 3;
} Age;

struct bs
{
	unsigned int a : 1;
	unsigned int b : 3;
	unsigned int c : 4;
} bit, *pbit;

int main()
{
	printf("--------1.位域初体验--------\n");
	printf("status1占用的字节数：%lu\n", sizeof(status1));
	printf("status2占用的字节数：%lu\n", sizeof(status2));


	printf("--------2.位域申明--------\n");
	printf("Age占用的字节数：%lu\n", sizeof(Age));
	// 0b100
	Age.age = 4;
	printf("Age.age : %d\n", Age.age);

	// 0b111
	Age.age = 7;
	printf("Age.age : %d\n", Age.age);

	// 警告：大整数隐式截断为无符号类型 [-Woverflow]
	// 0b1000
	Age.age = 8;
	printf("Age.age : %d\n", Age.age);


	printf("--------3.位域的使用--------\n");
	bit.a = 1;
	bit.b = 7;
	bit.c = 15;
	printf("%d, %d, %d\n", bit.a, bit.b, bit.c);

	pbit = &bit;
	pbit->a = 0;
	// 0b111 & 0b011 = 0b011 = 3
	pbit->b &= 3;
	// 0b1111 | 0b0001 = 0b1111 = 15
	pbit->c |= 1;
	printf("%d, %d, %d\n", pbit->a, pbit->b, pbit->c);
	return 0;
}