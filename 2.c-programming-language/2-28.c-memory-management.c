#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char name[100];
	char * description;

	printf("--------1.动态分配内存--------\n");
	strcpy(name, "hegongshan");
	printf("name = %s\n", name);

	// 动态分配内存
	description = (char *) malloc(50 * sizeof(char));
	if (description == NULL)
	{
		fprintf(stderr, "内存分配失败\n");
	} 
	else 
	{
		strcpy(description, "To be or not to be? This is a question. ");
	}
	printf("description = %s\n", description);


	printf("--------2.重新调整内存大小和释放内存--------\n");
	description = (char *) realloc(description, 100 * sizeof(char));
	if (description == NULL)
	{
		fprintf(stderr, "内存分配失败\n");
	} 
	else 
	{
		strcat(description, "Yesterday is history. Tomorrow is mystery. Today is a git.");
	}
	printf("description = %s\n", description);

	free(description);
	return 0;
}