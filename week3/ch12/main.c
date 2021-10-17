#include <stdio.h>
#include <stdlib.h>
#include "string.h"
 #define MAX_SIZE 1430
void huisu(int left,int right,int flag,int n,char* str,char** table,int* returnSize)
{
    if(flag==n*2)
    {
        table[(*returnSize)]=(char*)calloc((2*n+1),sizeof(char));
        strcpy(table[(*returnSize)++],str);
        return;
    }
    if(left<n)
    {
        str[flag]='(';
        huisu(left+1,right,flag+1,n,str,table,returnSize);
    }
    if(left>right)
    {
        str[flag]=')';
        huisu(left,right+1,flag+1,n,str,table,returnSize);
    }
}
char** generateParenthesis(int n, int *returnSize)
{
    char*  str=(char*)calloc((2*n+1),sizeof(char));
    char** table=malloc(sizeof(char*)*MAX_SIZE);
    *returnSize=0;
    huisu(0,0,0,n,str,table,returnSize);
    return table;
}
int main()
{
    printf("input:3\n");
    int returnSize=0;
    char** s=generateParenthesis(3,&returnSize);
    for(int i=0;i<returnSize;++i)
        printf("%s\n",s[i]);
    return 0;
}
