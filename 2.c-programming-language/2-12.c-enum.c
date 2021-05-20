#include <stdio.h>
#include <stdlib.h>

enum DAY 
{
	MON=1, TUE, WED, THU, FRI, SAT, SUN
};

int main()
{
	printf("------1.枚举变量的定义------\n");
	enum DAY day;
	day = WED;
	printf("%d\n", day);

	for (day = MON; day <= SUN; day++)
	{
		printf("枚举元素的值： %d\n", day);
	}


	enum COLOR {RED=1, GREEN, BLUE};
	enum COLOR favorite_color;
	printf("请输入您感兴趣的颜色（1.red，2.green，3.blue）：\n");
	scanf("%u", &favorite_color);

	switch(favorite_color)
	{
		case RED:
			printf("您喜欢的颜色为红色\n");
			break;
		case GREEN:
			printf("您喜欢的颜色为绿色\n");
			break;
		case BLUE:
			printf("您喜欢的颜色为蓝色\n");
			break;
		default:
			printf("您没有选择您喜欢的颜色\n");
	}


	printf("------2.将整数转换为枚举类型------\n");
	int a = 0;
	day = (enum DAY) a;
	printf("day = %d\n", day);
	return 0;
}