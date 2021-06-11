#include <stdio.h>

int main()
{
	printf("--------1.强制类型转换初体验--------\n");
	int sum = 17, count = 5;
	double mean = (double) sum / count;
	printf("%d / %d = %f\n", sum, count, mean);


	printf("--------2.整数提升--------\n");
	// char -> int
	int i = 17;
	char c = 'a'; // 97
	sum = i + c;
	printf("%d + %d = %d\n", i, c, sum);


	printf("--------3.算术转换--------\n");
	i = 17; // int -> float
	c = 'a'; // char -> int ->float
	float val = i + c;
	printf("%d + %d = %f\n", i, c, val);
	return 0;
}