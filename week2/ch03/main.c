#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *a = malloc(sizeof(int)*2);
    for(int i = 0;i < numsSize - 1;i++)
    {
        for(int j = i + 1;j < numsSize;j++)
        {
            if(nums[i] + nums[j] == target)
            {
                a[0] = i;
                a[1] = j;
                *returnSize = 2;
                return a;
            }
        }
    }
    return 0;
}
int main()
{
    int a[5]={1,2,3,4,5};
    int c=2;
    int* b=twoSum(a,5,9,&c);
    printf("%d",b[0]);
    printf("%d",b[1]);

    return 0;
}
