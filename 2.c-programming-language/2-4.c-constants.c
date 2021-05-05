#include <stdio.h>

#define PI 3.14
#define R 4

int main()
{
	printf("Hello\tWorld\n\n");

	// 1.测试#define
	float circleArea = R * PI * PI;
	printf("value of circle area: %.4f\n", circleArea);

	// 2.测试const
	const int LENGTH = 10;
	const int WIDTH = 5;
	const char NEWLINE = '\n';
	int rectangleArea = LENGTH * WIDTH;
	printf("value of rectangle area: %d\n", rectangleArea);
	printf("%c", NEWLINE);
	return 0;
}