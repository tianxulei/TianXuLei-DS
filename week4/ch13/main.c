#include <stdio.h>
#include <stdlib.h>
void nextPermutation(int* nums, int numsSize) 
{
	int Max = 10,flag;
	for (int i = 0; i < numsSize-1; ++i)
	{
		if (nums[numsSize - 1 - i] > Max)
		{
			Min = i;
			flag = numsSize - 1 - i;
		}
		if (nums[numsSize - i] < Max)
		{
			int tmp = nums[flag];
			nums[flag] = nums[numsSize - i];
			nums[numsSize - i] = tmp;
			i = numsSize - 1;
		}
	}
}
int main()
{
	int a[3] = { 1,2,3 };
	nextPermutation(a, 3);
	for (int i = 0; i < 3; ++i)
		printf("%d", a[i]);
	return 0;
}