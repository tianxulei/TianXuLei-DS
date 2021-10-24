#include<stdio.h>
#include<stdlib.h>
void Sort(int A[], int N, int true, int maybe, int false)
{
	int start = 0;
	for (int i = 0; i < N; ++i)
		if (A[i] == true)
		{
			A[i] = A[start];
			A[start++] = true;
		}
	for (int i = start; i < N; ++i)
		if (A[i] == maybe)
		{
			A[i] = A[start];
			A[start++] = maybe;
		}
}
int main()
{
	int A[10] = { 9,8,7,6,5,4,3,2,1,0 };
	Sort(A, 10, 1, 4, 7);
	for (int i = 0; i < 10; ++i)
		printf("%d", A[i]);
	return 0;
}