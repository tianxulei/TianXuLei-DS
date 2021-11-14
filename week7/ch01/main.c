#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a, const void* b)
{
	char* aa = *(char**)a;
	char* bb = *(char**)b;
	int len_a = strlen(aa);
	int len_b = strlen(bb);
	if (len_a != len_b)
		return len_a - len_b;

	//int tmp[26] = { 0 };
	int* tmp = calloc(26, sizeof(int));

	for (int i = 0; i < len_a; ++i)
	{
		tmp[aa[i] - 'a']++;
		tmp[bb[i] - 'a']--;
	}
	for (int i = 0; i < 26; ++i)
		if (tmp[i] != 0)
			return tmp[i];
	return 0;
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) 
{
	if (strsSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	char*** table = malloc(sizeof(char**) * strsSize);
	*returnColumnSizes = malloc(sizeof(int) * strsSize);
	qsort(strs, strsSize, sizeof(strs[0]), cmp);
	int i = 0,j;
	int idx = 0;
	while (i < strsSize)
	{
		j = i + 1;
		while (j < strsSize && cmp(strs+i, strs+j) == 0) ++j;
		table[idx] = malloc(sizeof(char*) * (j - i));
		for (int k = 0; k < j - i; ++k)
			table[idx][k] = strs[i + k];
		(*returnColumnSizes)[idx++] = j - i;
		i = j;
	}
	*returnSize = idx;
	return table;
}
int main()
{
	char** strs = malloc(sizeof(char*) * 6);
	for(int i=0;i<6;++i)
		strs[i] = calloc(4,sizeof(char));
	strs[0][0] = 'e'; strs[0][1] = 'a'; strs[0][2] = 't';
	strs[1][0] = 't'; strs[1][1] = 'e'; strs[1][2] = 'a';
	strs[2][0] = 't'; strs[2][1] = 'a'; strs[2][2] = 'n';
	strs[3][0] = 'a'; strs[3][1] = 't'; strs[3][2] = 'e';
	strs[4][0] = 'n'; strs[4][1] = 'a'; strs[4][2] = 't';
	strs[5][0] = 'b'; strs[5][1] = 'a'; strs[5][2] = 't';
	int returnSize;
	int* returnColumnSizes;
	char*** result = groupAnagrams(strs, 6, &returnSize, &returnColumnSizes);
	for (int i = 0; i < returnSize; ++i)
	{
		for (int j = 0; j < returnColumnSizes[i]; ++j)
			printf("%s\n", result[i][j]);
		printf("\n");
	}
	return 0;
}