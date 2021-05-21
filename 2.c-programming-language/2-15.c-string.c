#include <stdio.h>
#include <string.h>

int main()
{
	printf("------1.字符串初体验------\n");
	char site[] = "www.hegongshan.com";
	char names[10] = "hegongshan";
	printf("网址：%s\n", site);
	printf("姓名：%s\n", names);


	printf("------2.字符串函数------\n");
	char str1[14] = "runoob";
	char str2[14] = "google";
	char str3[14] = "";
	printf("str1 = %s, str2 = %s, str3 = %s\n", str1, str2, str3);

	// 复制str1到str3
	strcpy(str3, str1);
	printf("strcpy(str3, str1): %s\n", str3);

	// 拼接str1和str2
	strcat(str1, str2);
	printf("strcat(str1, str2): %s\n", str1);

	int len = strlen(str1);
	printf("拼接以后，str1的长度为: %d\n", len);
}