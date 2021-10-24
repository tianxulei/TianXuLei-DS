#include<stdio.h>
#include<stdlib.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
	*returnSize = 2;
	int returnNum[2] = {-1,-1};
	if (numsSize == 0) return returnNum;//数组长度为0
	if (nums[0] > target || nums[numsSize - 1] < target) return returnNum;//target超界
	if (numsSize == 1)//长度为1
	{
		if (nums[0] == target) returnNum[0] = returnNum[1] = 0;
		return returnNum;
	}
	if (nums[0] == target)
	{
		returnNum[0] = returnNum[1] = 0;
		int i=0;
		while (i < numsSize-1 && nums[i] == target) 
			++i; 
		returnNum[1] = i-1;
		if (nums[numsSize - 1] == target)
			returnNum[1] = numsSize - 1;
		return returnNum;
	}
	else if (nums[numsSize - 1] == target)
	{
		returnNum[1] = numsSize - 1;
		int i = 0;
		while (numsSize - i > 0 && nums[numsSize - 1 - i] == target)
			++i; 
		returnNum[0] = numsSize - i;
		if (nums[0] == target)
			returnNum[0] = 0;
		return returnNum;
	}
	int L = 0, R = numsSize - 1, Enter = (L + R) / 2;
	while (nums[Enter] != target && L+1 < R)
	{
		Enter = (L + R) / 2;
		if (nums[Enter] < target) L = Enter;
		if (nums[Enter] > target) R = Enter;
	}
	if (nums[Enter] == target)
	{
		int i = 0;
		while (Enter - i >= 0 && nums[Enter - i] == target)
			++i; 
		returnNum[0] =Enter - i + 1;
		i = 0;
		while (Enter + i <= numsSize - 1 && nums[Enter + i] == target)
			++i;
		returnNum[1] =Enter + i - 1;
	}
	printf("%d", returnNum[0]);
	printf("%d", returnNum[1]);
	return returnNum;
}
int main()
{
	int returnSize = 0;
	int a[2] = { 1,4 };
	int* b = searchRange(a, 2, 4, &returnSize);
	return 0;
}