#include <stdio.h>

int main()
{
	int c;
	char str[100];

	printf("--------1.getchar()和putchar()--------\n");
	printf("请输入一个字符：\n");
	c = getchar();

	printf("\n您输入的是：");
	putchar(c);
	printf("\n");
	// 处理换行符
	c = getchar();
	//printf("%d\n", c == '\n');


	printf("--------2.gets()和puts()--------\n");
	printf("请输入一个字符串：\n");
	//  警告：不建议使用‘gets’(声明于 /usr/include/stdio.h:638) [-Wdeprecated-declarations]
	gets(str);

	printf("\n您输入的是：");
	// 自动添加换行符
	puts(str);


	printf("--------3.scanf()和printf()--------\n");
	printf("请输入一个字符串和一个数字：\n");
	// 在读取字符串时，scanf遇到第一个空格就会停止读取
	scanf("%s %d", str, &c);
	printf("\n您输入的是：%s %d", str, c);
	putchar('\n');
	return 0;
}