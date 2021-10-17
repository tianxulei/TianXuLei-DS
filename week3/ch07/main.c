#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int cha(int a,int b)
{
    if(a>b)
        return a-b;
    else
        return b-a;
}
int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums,numsSize,sizeof(int),cmp);
    int L=0,R=0,min=10000,a=0;
    for(int i=0;i<numsSize-2;++i)//-3,0,1,2
    {
        printf("%d ",i);
        L=i+1;R=numsSize-1;
        while(L<R)
        {
            int num=nums[i]+nums[L]+nums[R];
            if(cha(target,num)<min)
            {
                min=cha(target,num);
                a=num;
            }
            if(num-target>0)
                R--;
            else
                L++;
        }
    }
    return a;
}
int main()
{
    int a[4]={0,2,1,-3};
    printf("%d",threeSumClosest(a,4,1));
    return 0;
}
