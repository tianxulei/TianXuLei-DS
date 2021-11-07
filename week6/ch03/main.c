#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char* multiply(char* num1, char* num2) 
{
    int len1 = strlen(num1), len2 = strlen(num2);
    if (len1 == 0 || len2 == 0)
        return;
    int result = 0, tmp = 0;
    for (int i = 0; i < len1; ++i)
    {
        tmp = 0;
        for (int j = 0; j < len2; ++j)
            tmp = tmp + pow(10, j) * (num1[len1 - 1 - i] - '0') * (num2[len2 - 1 - j] - '0');
        result = result + pow(10, i) * tmp;
    }
    int size = 0;
    tmp = result;
    while (tmp > 0)
    {
        tmp /= 10;
        size++;
    }
    char* end = malloc(sizeof(char) * (size + 1));
    end[size] = '\0';
    for (int i = 0; i < size; ++i)
    {
        end[size - 1 - i] = result % 10 + '0';
        result /= 10;
    }
    return end;
}
int main()
{
    char a[3] = { '2','5','\0' };
    char b[3] = { '2','5','\0' };
    printf("%s", multiply(a, b));
	return 0;
}