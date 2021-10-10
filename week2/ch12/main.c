#include <stdio.h>
#include <stdlib.h>
int maxArea(int* height, int heightSize)
{
    int start=0,end=heightSize-1,max=0,Max=0,min=0;
    while(start!=end)
    {
        min=(height[start]<height[end])?height[start]:height[end];
        max=(end-start)*min;
        if(max>Max)
            Max=max;
        if(height[start]>height[end])
            --end;
        else
            ++start;
    }
    return Max;
}
int main()
{
    int a[9]={1,8,6,2,5,4,8,3,7};
    int b=maxArea(a,9);
    printf("%d",b);
    return 0;
}
