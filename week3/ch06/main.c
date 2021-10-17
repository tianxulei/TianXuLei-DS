#include <stdio.h>
#include <stdlib.h>
#include "string.h"
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int min=200,size=0;
    if(strsSize<=1)
        return strs[0];
    for(int i=0;i<strsSize;++i)
    {
        if(strlen(strs[i])==0)
            return "";
        else if(strlen(strs[i])<min)
            min=strlen(strs[i]);
    }
    for(int i=0;i<min;++i)
    {
        size=i+1;
        for(int j=1;j<strsSize;++j)
        {
            if(strs[j][i]!=strs[j-1][i])
            {
                size=i;j=strsSize;i=min;
            }
        }
    }
    char* a=malloc((size+1)*sizeof(char));
    for(int i=0;i<size;++i)
        a[i]=strs[0][i];
    a[size]='\0';
    return a;
}
int main()
{
    char* a="fl";
    char* b="floweaaa";
    char* c="fleeee";
    char** strs=malloc(3*sizeof(char*));
    strs[0]=a;
    strs[1]=b;
    strs[2]=c;
    char* d=longestCommonPrefix(strs,3);
    printf("%s\n",d);
    return 0;
}
