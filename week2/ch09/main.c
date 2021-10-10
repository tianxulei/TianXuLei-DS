#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
int reverse(int x)
{
	long n = 0;
	while (x)
	{
		n = n * 10 + x % 10;
		x /= 10;
	}
	if(n>INT_MAX)
        return 0;
    if(n<INT_MIN)
        return 0;
	return n;
}
int main()
{
    int a=123;
    a=reverse(a);
    printf("%d",a);
    return 0;
}
