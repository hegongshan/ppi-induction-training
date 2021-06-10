#include <stdio.h>

#define FILE_SIZE 20
#undef FILE_SIZE
#define FILE_SIZE 100


#define message_for(a, b) \
	printf(#a " and " #b ": We love you!\n" );

#define tokenpaster(n) printf("token" #n " = %d\n", token##n);

#if !defined(MESSAGE)
	#define MESSAGE "Don't be the same, be better." 
#endif

#define square(x) x *x

#define max(x, y) ((x) > (y) ? (x) : (y))

int main()
{
	printf("--------1.预处理器初体验--------\n");
	printf("定义的FILE_SIZE = %d\n", FILE_SIZE);

	printf("--------2.测试预定义的宏--------\n");
	printf("当前文件为：%s\n", __FILE__);
	printf("当前日期：%s\n", __DATE__);
	printf("当前时间：%s\n", __TIME__);
	printf("当前行号：%d\n", __LINE__);
	printf("ANSI: %d\n", __STDC__);


	printf("--------3.测试预处理器运算符--------\n");
	// 字符串常量化运算符
	message_for(Linus, Knuth);
	
	// 标记粘贴运算符
	int token34 = 40;
	tokenpaster(34);

	printf("MESSAGE = %s\n", MESSAGE);


	printf("--------4.参数化的宏--------\n");
	// K&R P77，使用圆括号
	printf("不使用圆括号的square(10+1)：%d\n", square(10+1));
	printf("10和20中的最大值为：%d\n", max(10, 20));
	return 0;
}