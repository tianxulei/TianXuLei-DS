#include<stdio.h>
#include<stdlib.h>
void Shellsort(int* nums, int n)//Ï£¶ûÅÅÐò
{
	int i, j, Increment, tmp;
	for (Increment = n / 2; Increment > 0; Increment /= 2)
	{
		for (i = Increment; i < n; ++i)
		{
			tmp = nums[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				if (tmp < nums[j - Increment])
					nums[j] = nums[j - Increment];
				else
					break;
			}
			nums[j] = tmp;
		}
	}
}
int main()
{
	int a[5] = { 5,4,3,2,1 };
	printf("Ï£¶ûÅÅÐò£º");
	Shellsort(a, 5);
	for (int i = 0; i < 5; ++i)
		printf("%d", a[i]);
	return 0;
}