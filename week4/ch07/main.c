#include<stdio.h>
#include<stdlib.h>
//找出第k个最大值
int Select(int A[], int N, int k)
{
	int* nums = calloc(k+1,sizeof(int));
	for (int i = 0; i < N; ++i)
	{
		if (A[i] > nums[k])
		{
			nums[k] = A[i];
			int n = k;
			while (n > 0 && nums[n] > nums[n - 1])
			{
				int Tmp = nums[n];
				nums[n] = nums[n - 1];
				nums[n - 1] = Tmp;
				n--;
			}
		}
	}
	return nums[k];
}
int main()
{
	int a[6] = { 5,4,3,2,1,0 };
	printf("input:");
	for (int i = 0; i < 6; ++i)
		printf("%d", a[i]);
	printf("\noutput:");
	printf("%d", Select(a,6,3));
	return 0;
}