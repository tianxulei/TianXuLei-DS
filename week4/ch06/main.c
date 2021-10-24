#include<stdio.h>
#include<stdlib.h>
void Swap(int* a, int* b)
{
	int Tmp = *a;
	*a = *b;
	*b = Tmp;
}
int Median3(int A[], int Left, int Right)
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
void InsertionSort(int* nums, int n)
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
void Qselect(int A[],int k, int Left, int Right)
{
	int i, j;
	int Pivot;
	if (Left + Cutoff <= Right)
	{
		Pivot = Median3(A, Left, Right);
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
		if (k <= i)
			Qselect(A, k, Left, i - 1);
		else if (k > i + 1)
			Qselect(A, k, i + 1, Right);
	}
	else
		InsertionSort(A + Left, Right - Left + 1);
}
void Quicksort(int A[],int k, int N)
{
	Qselect(A, k, 0, N - 1);
}
int main()
{
	int a[10] = { 5,4,3,2,1,6,7,8,9,0 };
	printf("input:");
	for (int i = 0; i < 10; ++i)
		printf("%d", a[i]);
	printf("\noutput:");
	Quicksort(a, 3,10);
	printf("%d", a[3]);
	return 0;
}