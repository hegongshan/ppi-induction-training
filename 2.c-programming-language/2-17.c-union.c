#include <stdio.h>
#include <string.h>

union Data 
{
	int i;
	float f;
	char str[20];
};

int main()
{
	printf("------1.定义共用体------\n");
	union Data data;
	printf("共用体data占字节数：%d\n", sizeof(data));
	

	printf("------2.访问共用体成员------\n");
	data.i = 20;
	data.f = 100.5;
	strcpy(data.str, "hegongshan");
	printf("data.i: \t%d\n", data.i);
	printf("data.f: \t%f\n", data.f);
	printf("data.str: \t%s\n", data.str);

	
	data.i = 20;
	printf("data.i: \t%d\n", data.i);
	data.f = 100.5;
	printf("data.f: \t%f\n", data.f);
	strcpy(data.str, "hegongshan");
	printf("data.str: \t%s\n", data.str);

	return 0;
}