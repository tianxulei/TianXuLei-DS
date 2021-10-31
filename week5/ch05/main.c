#include<stdio.h>
#include<stdlib.h>
int trap(int* height, int heightSize) 
{
	int result = 0, max = 0;
	for (int i = 0; i < heightSize; ++i)
		if (height[i] > max)
			max = height[i];
	for (int i = 1; i <= max; ++i)
	{
		for (int j = 0; j < heightSize; ++j)
		{
			if (height[j] >= i)
			{
				int flag = 0, k = j+1;
				while (k<heightSize && height[k] < i)
				{
					++k;
					++flag;
				}
				if (k < heightSize)
					result += flag;
			}
		}
	}
	return result;
}
int main()
{
	int height[12] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	printf("%d", trap(height, 12));
	return 0;
}