#include <stdio.h>

// 使用static修饰全局变量
static int count = 10;
char name[] = "hegongshan";

void fun1();
extern void write();

int main()
{
	// 1.测试static
	while (count--)
	{
		fun1();
	}
	// 2.测试extern
	write();
	return 0;
}

void fun1()
{
	// 使用static修饰局部变量
	static int cnt = 5;
	cnt++;
	printf("cnt: %d, count: %d\n", cnt, count);
}