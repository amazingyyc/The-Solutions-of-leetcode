#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//最朴素的方法 为每一个'.'设为一个数字 然后判断是否可行
void solveSudoku(vector<vector<char> > &board) 
{
	sudoku(board);
}

bool sudoku(vector<vector<char> > &board)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if ('.' != board[i][j])
				continue;

			for (int c = '1'; c <= '9'; ++c)
			{
				board[i][j] = c;

				if (valid(board, i, j) && sudoku(board))
					return true;

				board[i][j] = '.';
			}

			return false;
		}
	}

	return true;
}

//判断[i, j]是否合法
bool valid(vector<vector<char> > &board, int i, int j)
{
	//行
	for (int m = 0; m < 9; ++m)
	{
		if (m != j && board[i][m] == board[i][j])
			return false;
	}

	//列
	for (int m = 0; m < 9; ++m)
	{
		if (m != i && board[m][j] == board[i][j])
			return false;
	}

	//块
	for (int m = (i / 3) * 3; m < (i / 3 + 1) * 3; ++m)
	{
		for (int n = (j / 3) * 3; n < (j / 3 + 1) * 3; ++n)
		{
			if ((m != i || n != j) && board[m][n] == board[i][j])
				return false;
		}
	}

	return true;
}

int main()
{
	return 1;
}