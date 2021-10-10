#include <stdio.h>
#include <stdlib.h>
#include "string.h"
char* convert(char* s, int numRows)
{
    if(numRows<=1)
        return s;
    int Num=2*numRows-2,//每组数
        num=(int)strlen(s)/Num,//整组数
        Num1=num*Num,//整数组长度
        yushu=strlen(s)%Num,//余数
        End=-1;
    char* a=malloc((strlen(s)+1)*sizeof(char));
    for(int i=0;i<num;++i)
        a[i]=s[i*Num];
    if(yushu>0)
    {
        a[num]=s[Num1];
        End=num;
    }
    else
        End=num-1;
    for(int i=1;i<=numRows-2;++i)
    {
        for(int j=0;j<num;++j)
            a[End+1+j*2]=s[i+j*Num];
        if(yushu>i)
            a[End+num*2+1]=s[Num1+i];
        for(int j=0;j<num;++j)
            a[End+2+j*2]=s[2*numRows-i-2+j*Num];
        if(yushu>2*numRows-i-2)
        {
            a[End+num*2+2]=s[Num1+2*numRows-i-2];
            End=End+num*2+2;
        }
        else if(yushu>i)
            End=End+num*2+1;
        else if(yushu<=i)
            End=End+2*num;
    }
    for(int i=0;i<num;++i)
        a[End+i+1]=s[numRows-1+i*Num];
    if(yushu>=numRows)
        a[End+num+1]=s[Num1-1+numRows];
    a[strlen(s)]='\0';
    return a;
}
int main()
{
    char* s="PAYPALISHIRING";
    char* a=convert(s,3);
    printf("%s\n",a);
    return 0;
}
