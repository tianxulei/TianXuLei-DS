#include<stdio.h>
#include<stdlib.h>
int FindEnter(int* nums, int numsSize, int target)
{
	if (numsSize == 1)
		return 0;
	int L = 0, R = numsSize - 1, Enter = numsSize;
	if (nums[L] < nums[R])
		return 0;
	while (L + 1 != R)
	{
		Enter = (L + R) / 2;
		if (nums[Enter] > nums[L])
			L = Enter;
		else if (nums[Enter] < nums[R])
			R = Enter;
	}
	if (nums[L] < nums[R])
		Enter = L;
	else
		Enter = R;
	return Enter;
}
int FindEnter1(int L, int R, int numSize)
{

	if (L < R)
		return (L + R) / 2;
	return (L + ((numSize - L) + R) / 2) % numSize;
}
int search(int* nums, int numsSize, int target)
{
	int start = FindEnter(nums, numsSize, target);
	if (numsSize == 1)
		return (nums[0]==target)-1;
	int L = start, R = (start+numsSize-1)%numsSize;
	int Enter = FindEnter1(L, R, numsSize);
	if (nums[L] > target || nums[R] < target)
		return -1;
	while (nums[Enter] != target && (L +1)%numsSize != R)
	{
		Enter = FindEnter1(L, R, numsSize);;
		if (nums[Enter] > target)
			R = Enter;
		else if (nums[Enter] < target)
			L = Enter;
		else
			return Enter;
	}
	if (nums[Enter] == target)
		return Enter;
	if (nums[L] == target)
		return L;
	if (nums[R] == target)
		return R;
	return -1;
}
int main()
{
	int a[3] = { 1,3,5 };
	printf("%d", search(a,3,3));
	return 0;
}