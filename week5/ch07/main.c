#include<stdio.h>
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	for (int i = digitsSize - 1; i >= 0; --i)
	{
		if (digits[i] < 9)
		{
			++digits[i];
			i = -1;
		}
		else
			digits[i] = 0;
	}
	if (digits[0] == 0)
	{
		int* a = calloc(digitsSize + 1, sizeof(int));
		if (a)
		{
			a[0] = 1;
			*returnSize = digitsSize + 1;
			return a;
		}
		
	}
	*returnSize = digitsSize;
	return digits;
}
int main()
{
	int returnSize = 0;
	int a[2] = { 9,9 };
	int* b = plusOne(a, 2, &returnSize);
	for (int i = 0; i < returnSize; ++i)
		printf("%d", b[i]);
	return 0;
}