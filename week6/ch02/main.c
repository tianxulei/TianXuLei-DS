#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int numsSize = 0;//处理后的尺寸

int* c;//处理后的数组
int* nums;//重复的个数

int ansSize;//
int* ansColumnSize;

int* combine;//过度数组
int combineSize;

int candidatesSize_tmp;

int** ans;

int* shanchu(int* a, int size, int target)//清除较大数
{
	for (int i = 0; i < size; ++i)
	{
		if (a[i] <= target)
			++numsSize;
		else
			a[i] = 0;
	}
	int* tmp = malloc(sizeof(int) * numsSize);
	if (tmp)
	{
		numsSize = 0;
		for (int i = 0; i < size; ++i)
		{
			if (a[i] != 0)
			{
				tmp[numsSize++] = a[i];
			}
		}
	}
	return tmp;
}
void paixv(int* a, int n)//排序
{
	int temp, i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i]; a[i] = a[j]; a[j] = temp;
			}	
		}
	}
}
int* chongfu(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
		if (a[i] == a[i + 1])
			--numsSize;
	int* tmp = malloc(sizeof(int) * numsSize);
	nums = malloc(sizeof(int) * numsSize);
	tmp[0] = a[0]; nums[0] = 1;
	numsSize = 1;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] == a[i - 1])
			nums[numsSize - 1]++;
		else
		{
			tmp[numsSize] = a[i];
			nums[numsSize++] = 1;
		}
	}
	return tmp;
}
int dfs(int idx,int target)
{
	if (target == 0)
	{
		int* tmp = malloc(sizeof(int) * combineSize);
		for (int i = 0; i < combineSize; ++i)
			tmp[i] = combine[i];
		ans[ansSize] = tmp;
		ansColumnSize[ansSize++] = combineSize;
		return;
	}
	if (idx == numsSize || target < c[idx])
		return;
	dfs(idx + 1, target);
	int most = fmin(target / c[idx], nums[idx]);
	for (int i = 1; i <= most; ++i)
	{
		combine[combineSize++] = c[idx];
		dfs(idx + 1, target - i * c[idx]);
	}
	combineSize -= most;
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{

	paixv(candidates, candidatesSize);
	numsSize = candidatesSize;
	c = chongfu(candidates, candidatesSize);

	ansSize = combineSize = 0;

	ans = malloc(sizeof(int*) * 2001);
	ansColumnSize = malloc(sizeof(int) * 2001);

	combine=malloc(sizeof(int)*2001);
	dfs(0,target);
	*returnSize = ansSize;
	*returnColumnSizes = ansColumnSize;
	return ans;
}
int main()
{
	int a[1] = { 2 };
	int returnSize;
	int* returnColumnSizes;
	int** table = combinationSum2(a, 1, 1, &returnSize, &returnColumnSizes);
	for (int i = 0; i < returnSize; ++i)
	{
		for (int j = 0; j < returnColumnSizes[i]; ++j)
			printf("%d", table[i][j]);
		printf("\n");
	}
	return 0;
}