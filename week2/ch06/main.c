#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int a=(nums1Size+nums2Size)/2+1;
    int* num=malloc(a*sizeof(int));
    int m=0,n=0;
    for(int i=0;i<a;++i)
    {
        if(m!=nums1Size && n!=nums2Size)
        {
            if(nums1[m]<nums2[n])
                num[i]=nums1[m++];
            else
                num[i]=nums2[n++];
        }
        else if(m==nums1Size)
            num[i]=nums2[n++];
        else if(n==nums2Size)
            num[i]=nums1[m++];
    }
    if((nums1Size+nums2Size)%2==0)
        return (double)(num[a-2]+num[a-1])/2;
    else
        return num[a-1];
}
int main()
{
    int num1[2]={1,2};
    int num2[2]={3,4};
    double a=findMedianSortedArrays(num1,2,num2,2);
    printf("%f",a);
    return 0;
}
