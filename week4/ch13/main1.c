#include <stdio.h>
#include <stdlib.h>
void nextPermutation(int* nums, int numsSize)
{
	int sign=0, flag=0,Min=100,flag2=-1,size=0;
	if (numsSize >= 2)
	{
		for (int i = 0; i < numsSize - 1; ++i)
		{
			if (nums[numsSize - 1 - i] > nums[numsSize - 2 - i])
			{
				flag = numsSize - 1 - i;
				i = numsSize;
			}
		}
		if (flag != 0)
		{
			for (int i = flag; i <= numsSize - 1; ++i)
			{
				if (nums[flag - 1] < nums[i])
					if (Min >= nums[i])
					{
						Min = nums[i];
						flag2 = i;
					}
			}
			int tmp = nums[flag - 1];
			nums[flag - 1] = nums[flag2];
			nums[flag2] = tmp;
		}
		size = (numsSize - flag) / 2;
		for (int i = flag,j=0; i < flag+size; ++i,++j)
		{
			int tmp = nums[i];
			nums[i] = nums[numsSize - 1 - j];
			nums[numsSize - 1 - j] = tmp;
		}
	}
}
int main()
{
	int a[53] = { 16,27,25,23,25,16,12,9,1,2,7,20,19,23,16,0,6,22,16,11,8,27,9,2,20,2,13,7,25,29,12,12,18,29,27,13,16,1,22,9,3,21,29,14,7,8,14,5,0,23,16,1,20 };
	nextPermutation(a, 53);
	for (int i = 0; i < 53; ++i)
		printf("%d", a[i]);
	return 0;
}