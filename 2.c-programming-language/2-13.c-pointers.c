#include <stdio.h>
#include  <time.h>

const int MAX = 4;

void get_seconds(unsigned long * ptr);

double avg(int * arr, int size);

int main()
{
	printf("------1.指针初体验------\n");
	int a = 100;
	int * p = &a;
	printf("变量a的地址为: %p\n", &a);
	printf("指针p存储的地址为: %p\n", p);
	printf("指针p指向的变量的值为：%d\n", *p);


	printf("------2.测试空指针------\n");
	int * ptr = NULL;
	printf("空指针存储的地址为：%p\n", ptr);


	printf("------3.指针的算术运算------\n");
	printf("递增指针...\n");
	int val[] = {10, 20, 100, 400};
	int * ptr2 = val;
	int i;
	for (i = 0; i < 4;  i++)
	{
		printf("存储地址：\tval[%d] = %p\n", i, ptr2);
		printf("存储值：\tval[%d] = %d\n", i, *ptr2);
		ptr2++;
	}

	printf("递减指针...\n");
	ptr2 = &val[MAX - 1];
	for (i = MAX; i > 0; i--)
	{
		printf("存储地址：\tval[%d] = %p\n", i - 1, ptr2);
		printf("存储值：\tval[%d] = %d\n", i - 1, *ptr2);
		ptr2--;
	}

	printf("指针比较...\n");
	ptr2 = val;
	for (ptr2 = val, i = 0; ptr2 <= &val[MAX - 1]; ptr2++, i++)
	{
		printf("存储地址：\tval[%d] = %p\n", i, ptr2);
		printf("存储值：\tval[%d] = %d\n", i, *ptr2);
	}


	printf("------4.指针数组------\n");
	int * ptr3[MAX];
	for (i = 0; i < MAX; i++)
	{
		ptr3[i] = &val[i];
	}
	for (i = 0; i < MAX; i++)
	{
		printf("val[%d] = %d\n", i, *ptr3[i]);
	}

	const char * names[] = {"CCNU", "WHU", "FUDAN", "MIT"};
	for (i = 0; i < MAX; i++)
	{
		// 注意：names前没有*号
		printf("names[%d] = %s\n", i, names[i]);
	}


	printf("------5.指向指针的指针------\n");
	int v = 100;
	int * pt1 = &v;
	int ** pt2 = &pt1;
	printf("v: \t%d\n", v);
	printf("指针pt1存储的地址: \t%p\n", pt1);
	printf("*pt1：\t%d\n", *pt1);

	printf("指针pt2存储的地址：\t%p\n", pt2);
	printf("**pt2的值：\t%d\n", **pt2);


	printf("------6.传递指针给函数------\n");
	unsigned long second;
	get_seconds(&second);
	printf("秒数为%lu\n", second);

	printf("测试数组作为函数参数...\n");
	int balance[5] = {1000, 2, 3, 17, 50};
	double avg_val  = avg(balance, 5);
	printf("平均值为：%f\n", avg_val);

}


void get_seconds(unsigned long * ptr)
{
	// 获取当前秒数
	*ptr = time(NULL);	
}

double avg(int * arr, int size)
{
	int i = 0;
	double sum  = 0.0d;
	for (i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}