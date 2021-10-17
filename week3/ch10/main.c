#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "stdbool.h"
bool isValid(char * s)
{
    char* stack=malloc(sizeof(char)*5001);
    int len=strlen(s),i=0,size=0;
    if(len<2)
        return false;
    while(i!=len)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            stack[size]=s[i];
            ++size;++i;
        }
        if(s[i]==')')
        {
            if(size==0)
                return false;
            else if(stack[size-1]=='(')
            {
                size--;++i;
            }
            else
                return false;
        }

        if(s[i]=='}')
        {
            if(size==0)
                return false;
            else if(stack[size-1]=='{')
            {
                size--;++i;
            }
            else
                return false;
        }

        if(s[i]==']')
        {
            if(size==0)
                return false;
            else if(stack[size-1]=='[')
            {
                size--;++i;
            }
            else
                return false;
        }

    }
    if(size!=0)
        return false;
    else
        return true;
}
int main()
{
    printf("input:");
    char a[6]="(){}\0";
    printf("%s\n",a);
    printf("output:");
    if(isValid(a))
        printf("true");
    else
        printf("false");
    return 0;
}
