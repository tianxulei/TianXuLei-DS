#include<stdio.h>
#include<stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) 
{
	*returnSize = matrixSize * (*matrixColSize);
	if (*returnSize == 0)
		return NULL;
	int* nums = malloc(sizeof(int) * (*returnSize));
	int derictions[4][2] = { 1,0,0,1,-1,0,0,-1 };//ÓÒ£¬ÏÂ£¬×ó£¬ÉÏ
	int deriction = 0;
	int i=0, j=0, idx=0;
	while (i < matrixSize && j < (*matrixColSize) &&
		i >= 0 && j >= 0 && matrix[i][j] != 101)
	{
		nums[idx++] = matrix[i][j];
		matrix[i][j] = 101;
		int m = i + derictions[deriction][1], n = j + derictions[deriction][0];
		if (m < matrixSize && n < (*matrixColSize) &&
			m>=0 && n>=0 && matrix[m][n] != 101)
		{
			i = m; j = n;
		}
		else
		{
			deriction = (deriction + 1) % 4;
			i += derictions[deriction][1];
			j += derictions[deriction][0];
		}
	}
	*returnSize = idx;
	return nums;
}
int main()
{
	int** nums = malloc(sizeof(int*) * 3);
	for (int i = 0; i < 3; ++i)
		nums[i] = malloc(sizeof(int) * 3);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			nums[i][j] = i * 3 + j + 1;
	int matrixColSize = 3;
	int returnSize;
	int* result = spiralOrder(nums, 3, &matrixColSize, &returnSize);
	for (int i = 0; i < returnSize; ++i)
		printf("%d", result[i]);
	return 0;
}