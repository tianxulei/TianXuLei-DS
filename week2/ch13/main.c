#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * intToRoman(int num)
{
    int a[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *b[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int c[13]={0};
    for(int i=0;i<13;++i)
    {
        c[i]=num/a[i];num=num%a[i];
    }
    char* d=malloc(16*sizeof(char));
    d[0]='\0';
    for(int i=0;i<13;++i)
    {
        for(int j=0;j<c[i];++j)
            strcpy(d+strlen(d),b[i]);
    }
    return d;
}

int main()
{
    int b=999;
    char* a=intToRoman(b);
    printf("%s\n",a);
    return 0;
}
