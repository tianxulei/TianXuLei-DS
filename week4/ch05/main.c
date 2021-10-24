#include<stdio.h>
#include<stdlib.h>
void Swap(int* a, int* b)
{
	int Tmp = *a;
	*a = *b;
	*b = Tmp;
}
int Medians(int A[], int Left, int Right)//返回一个中间值
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}
void InsertionSort(int* nums, int n)//插入排序
{
	int tmp, j;
	for (int i = 1; i < n; ++i)
	{
		tmp = nums[i];
		for (j = i; j > 0 && nums[j - 1] > tmp; --j)
			nums[j] = nums[j - 1];
		nums[j] = tmp;
	}
}
#define Cutoff ( 3 )
void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int Pivot;
	if (Left + Cutoff <= Right)
	{
		Pivot = Medians(A, Left, Right);
		i = Left; j = Right - 1;
		for (; ; )
		{
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			if (i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);
		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else
		InsertionSort(A + Left, Right - Left + 1);
}
void Quicksort(int A[], int N)
{
	Qsort(A, 0, N - 1);
}
int main()
{
	int a[5] = {5,4,3,2,1};
	printf("input:");
	for (int i = 0; i < 5; ++i)
		printf("%d", a[i]);
	printf("\noutput:");
	Quicksort(a, 5);
	for (int i = 0; i < 5; ++i)
		printf("%d", a[i]);
	return 0;
}