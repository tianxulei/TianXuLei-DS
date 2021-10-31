#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//bool isValidSudoku(char** board, int boardSize, int* boardColSize) 
bool isValidSudoku(char** board) 
{
	char Tmp;
	int flag, r, c;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			Tmp = board[i][j];
			if (Tmp != '.')
			{
				//横着检查
				flag = 0;
				for (int k = 0; k < 9; ++k)
					if (Tmp == board[i][k]) ++flag;
				if (flag > 1) return false;
				//竖着检查
				flag = 0;
				for (int k = 0; k < 9; ++k)
					if (Tmp == board[k][j]) ++flag;
				if (flag > 1) return false;
				//九宫格检查
				flag = 0;
				r = i / 3; c = j / 3;
				for (int m = 3 * r; m < 3 * r + 3; ++m)
				{
					for (int n = 3 * c; n < 3 * c + 3; ++n)
					{
						if (Tmp == board[m][n]) ++flag;
					}
				}
				if (flag > 1) return false;
			}
		}
	}
	return true;
}
int main()
{
	char* board[9] = 
	{	"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79"
		 };
	bool result = isValidSudoku(board);
	if (result)
		printf("%s", "true");
	else
		printf("%s", "false");
	return 0;
}