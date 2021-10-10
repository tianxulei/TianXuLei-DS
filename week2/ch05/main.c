#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int lengthOfLongestSubstring(char * s)
{

    int len=strlen(s),max=1,num1=1,num2=0,start=0,a=1;
    if(len==0)
        return 0;
    else
        while(a!=len)
        {
            num2=num1;
            for(int i=0;i<a-start;++i)
            {
                if(s[a]==s[start+i])
                {
                    start=start+i+1;num1=a-start+1;num2=0;
                }
            }
            if(num1==num2)
                num1++;
            if(num1>max)
                max=num1;
            ++a;
        }
    return max;

}
int main()
{
    char* s="cbdeb";

    int a=lengthOfLongestSubstring(s);
    printf("%d",a);

    return 0;
}
