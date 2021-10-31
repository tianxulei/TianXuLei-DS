#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lengthOfLastWord(char* s)
{
	int len = strlen(s);
	while (s[len - 1] == ' ')
		--len;
	int a = 0;
	while (len > 0 && s[len - 1] != ' ')
	{
		--len; ++a;
	}
	return a;
}
int main()
{
	char a[22] = "luffy is still joyboy";
	printf("%d", lengthOfLastWord(a));
	return 0;
}