#include<stdio.h>
#include<stdlib.h>
#define n (4)
int searchInsert(int* nums, int numsSize, int target) 
{
	if (target < nums[0]) return 0;
	else if (target > nums[numsSize - 1]) return numsSize;
	int left = 0, right = numsSize - 1, enter = (left + right) / 2;
	while (left + 1 < right && nums[enter] != target)
	{
		if (nums[enter] < target)
			left = enter;
		else if (nums[enter] > target)
			right = enter;
		enter = (left + right) / 2;
	}
	if (nums[right] == target) return right;
	else if (nums[enter] == target) return enter;
	return enter + 1;
}
int main()
{
	int nums[n] = { 1,3,5,6 };
	printf("%d", searchInsert(nums, n, 0));
	return 0;
}