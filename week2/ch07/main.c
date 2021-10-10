#include <stdio.h>
#include <stdlib.h>
#include "string.h"
char* longestPalindrome(char* s)
{
    int Size=strlen(s),j=1,max=0,Max=0,Max1=0,Locate=0,Locate1=0;
    if(Size<2)
        return s;
    for(int i=1;i<Size-1;++i)//1~Size-2
    {
        j=1;
        while(s[i-j]==s[i+j] && i-j>0 && i+j<Size-1)//
        {
            ++j;++max;
        }
        if(s[i-j]==s[i+j])
        {
            ++max;
        }
        if(max>Max)
        {
            Max=max;Locate=i;
        }
        j=1;
        max=0;
        while(s[i-j]==s[i+j-1] && i-j>0 && i+j<Size)//
        {
            ++j;++max;
        }
        if(s[i-j]==s[i+j-1])
        {
            ++max;
        }
        if(max>Max1)
        {
            Max1=max;Locate1=i;
        }
        max=0;
    }
    if(Max1==0 && Max==0)
    {
        if(s[Size-1]==s[Size-2])
        {
            Max1=1;Locate1=Size-1;
        }
    }
    if(Max>=Max1)
    {
        char* a=malloc((2*Max+2)*sizeof(char));
        for(int i=0;i<Max*2+1;++i)
            a[i]=s[Locate-Max+i];
        a[2*Max+1]='\0';
        return a;
    }
    else
    {
        char* a=malloc((2*Max1+1)*sizeof(char));
        for(int i=0;i<Max1*2;++i)
            a[i]=s[Locate1-Max1+i];
        a[2*Max1]='\0';
        return a;
    }
}
int main()
{
    char* s="cccccc";
    char* b=longestPalindrome(s);
    printf("%s",b);
    return 0;
}
