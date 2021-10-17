#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int romanToInt(char * s)
{
	int num=0;
	while(*s)
	{
		if(*s=='V')
			num+=5;
		else if(*s=='L')
			num+=50;
		else if(*s=='D')
			num+=500;
		else if(*s=='M')
			num+=1000;
		else if((*s=='I'&& *(s+1)=='V')||(*s=='I'&& *(s+1)=='X'))
            num-=1;
        else if(*s=='I')
            num+=1;
		else if((*s =='X'&&*(s+1)=='L')||(*s=='X'&& *(s+1)=='C'))
			num-=10;
        else if(*s =='X')
            num+=10;
		else if((*s =='C'&&*(s+1)=='D')||(*s=='C'&& *(s+1)=='M'))
			num-=100;
        else if(*s =='C')
            num+=100;
		s++;
		printf("%d\n",num);
	}
	return num;
}
int main()
{
    char *s=malloc(8*sizeof(char));
    s[0]='M';
    s[1]='C';
    s[2]='M';
    s[3]='X';
    s[4]='C';
    s[5]='I';
    s[6]='V';
    s[7]='\0';
    printf("%d\n",romanToInt(s));
    return 0;
}
