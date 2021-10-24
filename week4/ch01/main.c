#include<stdio.h>
#include<stdlib.h>
void InsertionSort(int* nums, int n)//≤Â»Î≈≈–Ú
{
	int tmp,j;
	for (int i = 1; i < n; ++i)
	{
		tmp = nums[i];
		for (j = i; j > 0 && nums[j - 1] > tmp; --j)
			nums[j] = nums[j - 1];
		nums[j] = tmp;
	}
}
int main()
{
	int a[5] = { 5,4,3,2,1 };
	printf("≤Â»Î≈≈–Ú£∫");
	InsertionSort(a, 5);
	for (int i = 0; i < 5; ++i)
		printf("%d", a[i]);
	return 0;
}