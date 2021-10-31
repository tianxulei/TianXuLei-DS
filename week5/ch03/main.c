#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* countAndSay(int n) 
{
    char p[5000]={'\0'};
    char p1[5000] = { '\0' };
    p[0] = '1';
    p[1] = '\0';
    int j;
    for (int i = 1; i < n; ++i) 
    {
        int x = 0;
        for (j = 0; p[j]; ++j) 
        {
            int y = 1;
            while (p[j + 1] && p[j] == p[j + 1]) 
            {
                ++y;
                ++j;
            }
            p1[x++] = y + 48;
            p1[x++] = p[j];
        }
        for (int k = 0; k < j; ++k)//Çå¿Õp
            p[k] = '\0';
        for (int k = 0; k < x; ++k)//¸´ÖÆ
            p[k] = p1[k];
        for (int k = 0; k <= x; ++k)
            p1[k] = '\0';
    }
    return p;
}
int main()
{
	int n = 5;
	printf("%s", countAndSay(n));
	return 0;
}