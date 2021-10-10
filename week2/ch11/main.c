#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPalindrome(int x)
{
    if(x<0 || (x!=0 && x%10==0))
        return false;
    else
    {
        int a=0;
        while(a<x)
        {
            a=a*10+x%10;
            x=x/10;
        }
        return a==x || x==a/10;
    }

}
int main()
{
    int a=101;
    if(isPalindrome(a))
        printf("yes");
    else
        printf("no");

    return 0;
}
