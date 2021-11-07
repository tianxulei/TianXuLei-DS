#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
double youPow(double x, int n) 
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2)
        return youPow(x * x, n / 2) * x;
    else
        return youPow(x * x, n / 2);
}
double myPow(double x, int n)
{
    long N = n;
    if (N < 0)
        return 1 / youPow(x, -N);
    else
        return youPow(x, N);
}
int main()
{
    printf("%f", myPow(5, 2));
	return 0;
}