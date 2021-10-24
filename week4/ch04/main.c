#include<stdio.h>
#include<stdlib.h>
#define LeftChild(i)(2*(i)+1)
void Swap(int* a, int* b)
{
	int Tmp = *a;
	*a = *b;
	*b = Tmp;
}
void PercDown(int* A, int i, int N)
{
	int Child;
	int Tmp;
	for (Tmp = A[i]; LeftChild(i) < N; i = Child)
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;
}
void Heapsort(int* A, int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)
		PercDown(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}
int main()
{
	int A[5] = { 5,4,3,2,1 };
	Heapsort(A, 5);
	for (int i = 0; i < 5; ++i)
		printf("%d", A[i]);
	return 0;
}