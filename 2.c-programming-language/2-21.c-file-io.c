#include <stdio.h>


int main(int argc, char * argv[])
{
	// printf("参数个数：%d\n", argc,);
	// printf("调用程序的程序名：%s\n", argv[0]);
	FILE * fp = NULL;

	printf("--------1.写入文件--------\n");
	printf("写/tmp/test.txt\n");
	fp = fopen("/tmp/test.txt", "w+");
	fprintf(fp, "测试 fprintf...\n");
	fputs("测试 fputs....\n", fp);
	fclose(fp);


	printf("--------2.读取文件--------\n");
	char buff[255];
	fp = fopen("/tmp/test.txt", "r");
	
	fscanf(fp, "%s", buff);
	printf("(1)使用fscanf读取: %s\n", buff);
	
	fgets(buff, 255, fp);
	printf("(2)使用fgets读取: %s\n", buff);
	
	fgets(buff, 255, fp);
	printf("(3)使用fgets读取: %s\n", buff);
	return 0;
}