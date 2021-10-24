#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int strStr(char * haystack, char * needle)
{
    int s1=strlen(haystack),s2=strlen(needle);
    if(s1==0 && s2!=0)
        return -1;
    if(s2==0)
        return 0;
    if(s2>s1)
        return -1;
    for(int i=0;i<=(s1-s2);++i)
    {
        if(haystack[i]==needle[0])
        {
            int j=1;
            while(j<s2 && haystack[i+j]==needle[j])
                ++j;
            if(j==s2)
                return i;
        }
    }
    return -1;
}
int main()
{
    char str1[5]="hello";
    char str2[2]="ll";
    int a=strStr(str1,str2);
    printf("%d",a);
    return 0;
}
