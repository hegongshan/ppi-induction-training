#include <stdio.h>

extern char name[];

void write(void)
{
	printf("count is %s\n", name);
}