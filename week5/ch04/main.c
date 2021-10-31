#include<stdio.h>
#include<stdlib.h>
#define numSize (3)
int firstMissingPositive(int* nums, int numsSize) 
{
	int a[numSize+2] = { 0 };
	for (int i = 0; i < numsSize; ++i)
		if (nums[i] > 0 && nums[i] <= numsSize)
			a[nums[i]] = 1;
	for (int i = 1; i <= numsSize+1; ++i)
		if (a[i] == 0)
			return i;
}
int main()
{
	int nums[numSize] = { 1,2,0 };
	printf("%d", firstMissingPositive(nums, numSize));
	return 0;
}