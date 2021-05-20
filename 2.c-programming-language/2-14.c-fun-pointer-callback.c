#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
	return x >= y ? x : y;
}

void populate_array(int * arr, size_t size, int (* getNextVal)(void))
{
	size_t i;
	for (i = 0; i < size; i++)
	{
		arr[i] = getNextVal();
	}
}

int main()
{
	printf("------1.函数指针------\n");
	// 函数指针
	int (* p)(int, int) = &max;

	int a, b, c, d;
	printf("请输入三个数字：\n");
	scanf("%d %d %d", &a, &b, &c);
	d  = p(p(a, b), c);
	printf("三者中最大的数字为:%d\n", d);


	printf("------2.回调函数------\n");
	int i;
	int arr[10];
	// 通过函数指针可以实现函数式编程
	populate_array(arr, 10, rand);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}