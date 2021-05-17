#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("------1.while循环--------\n");
	int a = 10;
	while (a < 20)
	{
		printf("a的值为：%d\n", a);
		a++;
	}


	printf("------2.for循环------\n");
	for (a = 10; a < 20; a++ )
	{
		printf("a的值为：%d\n", a);
	}


	printf("------3.do-while循环------\n");
	a = 10;
	do 
	{
		printf("a的值为：%d\n", a);
		a = a + 1;

	} while (a < 20);


	printf("------4.嵌套循环------\n");
	int i, j;
	// 寻找2-100内的质数
	for (i = 2; i < 100; i++) 
	{
		for (j = 2; j <= (i / j); j++) 
		{
			if (i % j == 0) 
			{
				break;
			}
		}
		if (j > (i / j))
		{
			printf("%d 是质数\n", i);
		}
	}


	// while嵌套
	i = 1;
	while (i <= 5)
	{
		j = 1;
		while (j <= i)
		{
			printf("%d ", j);
			j++;
		}
		printf("\n");
		i++;
	}


	// do...while嵌套
	i = 1;
	do
	{
		j = 1;
		do
		{
			printf("*");
			j++;
		} while (j <= i);
		printf("\n");
		i++;
	} while (i <= 5);


	printf("------5.break语句------\n");
	a = 10;
	// 10-15
	while (a < 20)
	{
		printf("a的值为：%d\n", a);
		a++;
		if (a > 15)
		{
			break;
		}
	}


	printf("------6.continue语句------\n");
	a = 10;
	do 
	{
		if (a == 15) 
		{
			a ++;
			continue;
		}
		printf("a的值为：%d\n", a);
		a++;
	} while (a < 20);


	printf("------7.goto语句------\n");
	a = 10;
	LOOP: do
	{
		if (a == 15)
		{
			a ++;
			goto LOOP;
		}
		printf("a的值为：%d\n", a);
		a++;
	} while (a < 20);


	printf("------8.无限循环------\n");
	// 自旋
	for (;;)
	{
		printf("该循环会永远执行下去！\n");
		sleep(1);
	}
	return 0;
}