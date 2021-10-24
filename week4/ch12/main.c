#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
int divide(int dividend, int divisor)
{
    long long did=dividend,div=divisor;
    long long quo=0;
    int  sign=0;

    if( did<0 ){ sign = !sign; did = -did; }
    if( div<0 ){ sign = !sign; div = -div; }

    for(int i=31;i>=0 && did>=div;--i)
    {
        if(did>=(div<<i))
        {
            quo=quo+((long long)1<<i);
            did=did-(div<<i);
        }
    }
    quo = (sign==1) ? -quo : quo;
    return  ( quo<INT_MIN || quo>INT_MAX ) ? INT_MAX : quo;
}
int main()
{
    printf("%d",divide(-2147483648,-1));
    return 0;
}
