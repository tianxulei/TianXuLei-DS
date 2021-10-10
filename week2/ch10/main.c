#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"
int myAtoi(char * s)
{
    int len=strlen(s),
         start=0,
         end=0,
         fuhao=1,
         i=0,
         num=0,
         a=0;
    while(s[i]==' ' && i<len)
        ++i;

    if(s[i]=='-')
    {
        fuhao=0;
        ++i;
        start=i;
    }
    else if(s[i]=='+')
    {
        ++i;
        start=i;
    }
    else if(atoi(&s[i])>0)
        start=i;
    else if(atoi(&s[i])==0 && s[i]!='0')
        return 0;

    while(s[i]=='0')
    {
        ++i;
        start=i;
    }
    while(atoi(&s[i])!=0 && s[i]!='0')
        ++i;
    end=i-1;
    num=end-start+1;
    char k=' ';
    int t=0;
    for(int j=0;j<num;++j)
    {
        k=*(s+start+j);
        t=atoi(&k);
        a=a*10+t;
    }
    if(fuhao==0)
        a=a*(-1);
    if(a>INT_MAX)
        return INT_MAX;
    if(a<INT_MIN)
        return INT_MIN;
	return a;
}
int main()
{
    char* s="12345";
    int b=myAtoi(s);
    printf("%d\n",b);
    return 0;
}
