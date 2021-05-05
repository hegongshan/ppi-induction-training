#include <stdio.h>

int x, y;

int add() 
{
	extern int x, y;
	x = 10;
	y = 20;
	return x + y;
}

int a = 1, b = 2;
int main()
{
	int result = add();
	int result2 = add2();
	printf("result 为 : %d\n", result);
	printf("result2 为 : %d\n", result2);
	return 0;
}