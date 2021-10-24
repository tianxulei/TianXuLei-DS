#include <stdio.h>
#include <stdlib.h>
int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize==0)
        return 0;
    int size=numsSize-1;
    while(size!=-1 && nums[size]==val)
        --size;
    for(int i=0;i<size+1;++i)
        if(nums[i]==val)
            nums[i--]=nums[size--];
    return size+1;
}
int main()
{
    int a[1]={1};
    int size=removeElement(a,1,1);
    for(int i=0;i<size;++i)
        printf("%d",a[i]);
    return 0;
}
