#include <stdio.h>
#include <stdlib.h>
#include "string.h"
char word[10][5] =
    {"000","000","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void huisu(char **table,int flag,int len,char * digits,int* returnSize,char* a)
{
    if(flag==len)
    {
        table[*returnSize]=malloc(sizeof(char)*(len+1));
        strcpy(table[*returnSize],a);
        (*returnSize)++;
        return ;
    }
    for(int i=0;i<strlen(word[digits[flag]-'0']);++i)
    {
        a[flag]=word[digits[flag]-'0'][i];
        huisu(table,flag+1,len,digits,returnSize,a);
    }
    return;
}
char ** letterCombinations(char * digits, int* returnSize)
{
    if(digits==NULL)//¿ÕÖ¸Õë
    {
        *returnSize=0;
        return NULL;
    }
    int len=strlen(digits);
    if(len==0)
    {
        *returnSize=0;
        return NULL;
    }

    char **table=malloc(sizeof(char*)*256);
    memset(table,0,sizeof(char*)*256);
    char *a=malloc(sizeof(char)*(len+1));
    memset(a,0,sizeof(char)*(len+1));
    *returnSize=0;
    huisu(table,0,len,digits,returnSize,a);
    return table;
}
int main()
{
    char* digits=malloc(sizeof(char)*3);
    digits[0]='2';digits[1]='3';digits[2]='\0';
    int e=0;
    int* returnSize=&e;
    char** a=letterCombinations(digits,returnSize);
    printf("input:");printf("%s\n",digits);
    printf("output:");
    for(int i=0;i<6;++i)
        printf("%s ",a[i]);
    return 0;
}
