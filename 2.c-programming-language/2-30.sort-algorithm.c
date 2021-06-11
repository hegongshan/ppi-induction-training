#include <stdio.h>

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 1. 冒泡排序
void bubble_sort(int arr[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++) 
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

// 2.选择排序
void selection_sort(int arr[], int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
	{
		int min = i;
		for (j = i; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&arr[i], &arr[min]);
		}
	}
}

// 3.插入排序
void insertion_sort(int arr[], int len)
{
	int i, j, temp;
	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

// 4.希尔排序
void shell_sort(int arr[], int len)
{
	int gap, i, j, temp;
	for (gap  = len >> 1; gap > 0; gap >>= 1)
	{
		for (i = gap; i < len ; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
			{
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
	}
}

// 5.归并排序
void merge_sort_recursion(int arr[], int temp[], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	
	int mid = (low + high) >> 1;
	merge_sort_recursion(arr, temp, low, mid);
	merge_sort_recursion(arr, temp, mid + 1, high);

	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		} 
		else 
		{
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while (j <= mid)
	{
		temp[k++] = arr[j++];
	}
	for (k = low; k <= high; k++)
	{
		arr[k] = temp[k];
	}
}

void merge_sort(int arr[], const int len)
{
	int temp[len];
	merge_sort_recursion(arr, temp, 0, len - 1);
}

// 6.快速排序
void quick_sort_recursion(int arr[], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int pivot = arr[low];
	int i = low;
	int j = high;
	while (i < j)
	{	
		// 从后往前找小于pivot的元素
		while (i < j && arr[j] >= pivot)
		{
			j--;
		}
		if (i < j)
		{
			arr[i++] = arr[j];
		}
		// 从前往后找大于pivot的元素
		while (i < j && arr[i] <= pivot)
		{
			i++;
		}
		if (i < j)
		{
			arr[j--] = arr[i];
		}
	}
	arr[i] = pivot;
	quick_sort_recursion(arr, low, i - 1);
	quick_sort_recursion(arr, i + 1, high);
}

void qucik_sort(int arr[], const int len)
{
	quick_sort_recursion(arr, 0, len - 1);
}

void print_arr(int arr[], const int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (i > 0) {
			putchar(' ');
		}
		printf("%d", arr[i]);
	}
	putchar('\n');
}


int main()
{
	printf("--------1.使用冒泡排序--------\n");	
	int arr1[] = { 27, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len1 = (int) sizeof(arr1) / sizeof(*arr1);
	bubble_sort(arr1, len1);
	print_arr(arr1, len1);


	printf("--------2.使用选择排序--------\n");
	int arr2[] = { 27, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len2 = (int) sizeof(arr2) / sizeof(*arr2);
	selection_sort(arr2, len2);
	print_arr(arr2, len2);


	printf("--------3.使用插入排序--------\n");
	int arr3[] = { 27, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len3 = (int) sizeof(arr3) / sizeof(*arr3);
	selection_sort(arr3, len3);
	print_arr(arr3, len3);


	printf("--------4.使用希尔排序--------\n");
	int arr4[] = { 27, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len4 = (int) sizeof(arr4) / sizeof(*arr4);
	selection_sort(arr4, len4);
	print_arr(arr4, len4);


	printf("--------5.使用归并排序--------\n");
	int arr5[] = { 27, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len5 = (int) sizeof(arr5) / sizeof(*arr5);
	selection_sort(arr5, len5);
	print_arr(arr5, len5);


	printf("--------6.使用快速排序--------\n");
	int arr6[] = { 27, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len6 = (int) sizeof(arr6) / sizeof(*arr6);
	selection_sort(arr6, len6);
	print_arr(arr6, len6);
	return 0;
}