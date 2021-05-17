#include <stdio.h>

int main()
{
	printf("------1.if语句------\n");
	int a = 10;
	printf("a的值为%d\n", a);
	if (a < 20)
	{
		printf("a < 20\n");
	}


	printf("------2.if...else语句------\n");
	a = 100;
	printf("a的值为%d\n", a);
	if (a < 20)
	{
		printf("a小于20\n");
	}
	else
	{
		printf("a大于或等于20\n");
	}

	if (a == 10)
	{
		printf("a的值为10\n");
	}
	else if (a == 20)
	{
		printf("a的值为20\n");
	}
	else if (a == 30)
	{
		printf("a的值为30\n");
	}
	else 
	{
		printf("没有匹配的值\n");
	}


	printf("------3.嵌套if------\n");
	a = 100;
	int b = 200;
	printf("a的准确值为%d\n", a);
	printf("b的准确值为%d\n", b);
	if (a == 100)
	{
		if (b == 200)
		{
			printf("a 的值为 100, b 的值为 200\n");
		}
	}


	printf("------4.switch语句------\n");
	char grade = 'B';
	printf("您的成绩是%c\n", grade);
	switch (grade)
	{
		case 'A':
			printf("很棒!\n");
			break;
		case 'B':
		case 'C':
			printf("做得好!\n");
			break;
		case 'D':
			printf("您通过了!\n");
			break;
		case 'F':
			printf("最好再试一下!\n");
			break;
		default :
			printf("无效的成绩!\n");
	}


	printf("------5.嵌套switch------\n");
	a = 100;
	b = 200;
	printf("a的准确值为%d\n", a);
	printf("b的准确值为%d\n", b);
	switch (a)
	{
		case 100:
			printf("这是外部switch的一部分\n");
			switch (b)
			{
				case 200:
					printf("这是内部switch的一部分\n");
			}
	}


	printf("------6.三元运算符------\n");
	int num;
	printf("请输入一个整数\n");
	scanf("%d", &num);
	num & 0x1 == 1 ? printf("%d是奇数\n", num) : printf("%d是偶数\n", num);
	return 0;
}