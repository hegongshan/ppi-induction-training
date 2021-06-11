#include <stdio.h>

int main(int argc, char * argv[])
{
	printf("--------命令行参数--------\n");
	printf("程序名称：%s\n", argv[0]);

	if (argc == 2)
	{
		printf("输入的参数为：%s\n", argv[1]);
	} 
	else if (argc > 2)
	{
		printf("输入的参数太多了\n");
	}
	else
	{
		printf("需要输入一个参数\n");
	}
	return 0;
}