#include<stdio.h>
#include<stdlib.h>
int candidatesSize_tmp;
int ansSize;
int combineSize;
int* ansColumnSize;
void dfs(int* candidates, int target, int** ans, int* combine, int idx) 
{
	//到底
	if (idx == candidatesSize_tmp)
		return;
	//符合
	if (target == 0)
	{
		int* tmp = malloc(sizeof(int) * combineSize);
		for (int i = 0; i < combineSize; ++i)
			tmp[i] = combine[i];
		ans[ansSize] = tmp;
		ansColumnSize[ansSize++] = combineSize;
		return;
	}
	//跳过
	dfs(candidates, target, ans, combine, idx + 1);
	//原地
	if (target - candidates[idx] >= 0)
	{
		combine[combineSize++] = candidates[idx];
		dfs(candidates, target - candidates[idx], ans, combine, idx);
		combineSize--;
	}
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) 
{
	candidatesSize_tmp = candidatesSize;
	ansSize = combineSize = 0;
	int** ans = malloc(sizeof(int*) * 1001);
	ansColumnSize = malloc(sizeof(int) * 1001);
	int combine[2001];
	dfs(candidates, target, ans, combine, 0);
	*returnSize = ansSize;
	*returnColumnSizes = ansColumnSize;
	return ans;
}
int main()
{
	int returnSize = 0;
	int* returnColumnSizes;
	int* candidates[4] = { 2, 3, 6, 7 };
	int** ans = combinationSum(candidates, 4, 7, &returnSize, &returnColumnSizes);
	for (int i = 0; i < returnSize; ++i)
	{
		for (int j = 0; j < returnColumnSizes[i]; ++j)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}