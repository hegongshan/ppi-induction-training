#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double avg(int arr[], int size);

int * get_random();

int main()
{
	int n[10];
	int i, j;

	for (i = 0; i < 10; i++) 
	{
		n[i] = i + 100;
	}

	for (i = 0; i < 10; i++)
	{
		printf("a[i] = %d\n", n[i]);
	}


	printf("------1.多维数组------\n");
	int a[5][2] = {{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}};
	for (i = 0; i < 5; i++) 
	{
		for (j = 0; j < 2; j++)
		{
			printf("a[%d][%d] = %d\n", i, j, a[i][j]);
		}
	}


	printf("------2.传递数组给函数------\n");
	int balance[5] = {1000, 2, 3, 17, 50};
	for (i = 0; i < 5; i ++)
	{
		printf("%d ", balance[i]);
	}
	printf("\n");

	double avg_val = avg(balance, 5);
	printf("balance的平均值: %f\n", avg_val);


	printf("------3.从函数返回数组------\n");
	int * p = get_random();
	for (i = 0; i < 10; i++)
	{
		printf("*(p + %d) = %d\n", i, *(p + i));
	}


	printf("------4.指向数组的指针------\n");
	double balance2[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
	double * p2 = balance2;
	printf("使用指针访问数组值\n");
	for (i = 0; i < 5; i++)
	{
		printf("*(p2 + %d) = %f\n", i, *(p2 + i));
	}

	printf("使用数组名作为地址访问数组值\n");
	for (i = 0; i < 5; i++)
	{
		printf("*(balance2 + %d) = %f\n", i, *(balance2 + i));
	}


	return 0;
}

double avg(int arr[], int size)
{
	int i;
	double sum = 0;
	for (i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

int * get_random()
{
	static int r[10];
	int i;

	srand((unsigned) time(NULL));
	for (i = 0; i < 10; i ++)
	{
		r[i] = rand();
		printf("r[%d] = %d\n", i, r[i]);
	}
	return r;
}