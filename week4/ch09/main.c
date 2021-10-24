#include <stdio.h>
#include <stdlib.h>
int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize<2)
        return numsSize;
    int start=0,num=numsSize;
    for(int i=1;i<numsSize;++i)
    {
        if(nums[i]!=nums[i-1])
            nums[++start]=nums[i];
        else
            --num;
    }
    return num;
}
int main()
{
    int a[5]={1,1,2,2,3};
    int size=removeDuplicates(a,5);
    for(int i=0;i<size;++i)
        printf("%d",a[i]);
    return 0;
}
