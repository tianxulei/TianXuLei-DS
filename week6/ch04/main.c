#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* nums;
int len;
int size = 0;
void dfs(int* nums, int idx,int** ans)
{
	if (idx == len - 1)
	{
		for (int i = 0; i < len; ++i)
		{
			ans[size][i] = nums[i];
		}
		size++;
		return;
	}
	for (int i = idx; i < len; ++i)
	{
		int temp = nums[i];
		nums[i] = nums[idx];
		nums[idx] = temp;
		dfs(nums, idx + 1, ans);
		nums[idx] = nums[i];
		nums[i] = temp;
	}
	return;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
	int a = 1;
	for (int i = 1; i <= numsSize; ++i)
		a *= i;
	int** ans = malloc(sizeof(int*) * a);
	for (int i = 0; i < a; ++i)
		ans[i] = malloc(sizeof(int) * numsSize);
	len = numsSize;
	dfs(nums, 0, ans);
	*returnSize = a;
	 *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < (*returnSize); i++) 
	{
		(*returnColumnSizes)[i] = numsSize;
	}
	return ans;
}
int main()
{
	int returnSize;
	int* returnColumnSizes;
	int a[2] = { 0,1 };
	int** ans = permute(a, 2, &returnSize, &returnColumnSizes);
	for (int i = 0; i < returnSize; ++i)
	{
		for (int j = 0; j < returnColumnSizes[i]; ++j)
			printf("%d", ans[i][j]);
		printf("\n");
	}
	return 0;
}