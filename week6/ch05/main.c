#include<stdio.h>
#include<stdlib.h>
#define n (3)
void rotate(int** matrix, int matrixSize) 
{
	int* tmp = malloc(matrixSize * sizeof(int));
	for (int i = matrixSize; i > 1; i -= 2)
	{
		int a = (matrixSize - i) / 2;
		for (int j = 0; j < i; ++j)
			tmp[j] = matrix[a + j][a];
		for (int j = 0; j < i - 1; ++j)
			matrix[a + j + 1][a]=
			matrix[matrixSize - a - 1][a + j + 1];
		for (int j = 0; j < i - 1; ++j)
			matrix[matrixSize - a - 1][a + j + 1]=
			matrix[matrixSize - a - j - 2][matrixSize - a - 1];
		for (int j = 0; j < i - 2; ++j)
			matrix[matrixSize - a - j - 2][matrixSize - a - 1] =
			matrix[a][matrixSize - 2 - a - j];
		for (int j = 0; j < i; ++j)
			matrix[a][matrixSize - 1 - j - a] = tmp[j];
	}
}
int main()
{
	int** b = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
	{
		b[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; ++j)
			b[i][j] = i * 3 + j;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	rotate(b, n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	return 0;
}