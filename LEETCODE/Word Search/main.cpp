#include <iostream>
#include <vector>

using namespace std;


/************************************************************************/
/* 

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
/************************************************************************/

//index为word的索引 size为word的长度 ij表示 在board中的行号的
//bool exitStr(vector<vector<char>> &board, int i, int j, int** step, int* take, string word, int index)
//{
//	int m = board.size();	//m行 n列
//	int n = board[0].size();
//
//	if (take[i*n + j]) return false;
//	if (index >= word.size())	return true;
//
//	if (index == word.size() - 1)
//	{
//		if (board[i][j] == word[index])
//			return true;
//	}
//
//	if (0 == step[i*n + j][index])	
//		return false;
//
//	if (board[i][j] != word[index])
//	{
//		step[i*n + j][index] = 0;
//
//		return false;
//	}
//
//	bool exit = false;
//
//	take[i*n + j] = 1;
//
//	//进行4个方向的搜索
//	for (int k = 0; k < 4; ++k)
//	{
//		switch (k)
//		{
//		case 0:
//		{
//				  if (0 == i)	break;
//				  exit = exitStr(board, i - 1, j, step, take, word, index + 1);
//		}
//			break;
//		case 1:
//		{
//				  if (j == n - 1)break;
//				  exit = exitStr(board, i, j + 1, step, take, word, index + 1);
//		}
//			break;
//		case 2:
//		{
//				  if (i == m - 1)break;
//				  exit = exitStr(board, i + 1, j, step, take, word, index + 1);
//		}
//			break;
//		case 3:
//		{
//				  if (0 == j)break;
//				  exit = exitStr(board, i, j - 1, step, take, word, index + 1);
//		}
//			break;
//		default:
//			break;
//		}
//
//		if (exit)	break;
//	}
//
//	take[i*n + j] = 0;
//
//	if (!exit)	step[i*n + j][index] = 0;
//
//	return exit;
//}
//
//bool exist(vector<vector<char>> &board, string word) 
//{
//	if ("" == word)	return true;
//	if (board.empty()) return false;
//
//	int m = board.size();	//m行 n列
//	int n = board[0].size();
//	int num = m*n;
//	int len = word.size();
//
//
//	/************************************************************************/
//	/*
//	take用来表示再一次搜索中当前take(i*n+j)(ij)是否已经被占用
//	step用来表示step[k(ij)][index]word的index小标字符是否可以通过k(ij) 为1表示可以通过 为0表示不可以 
//	*/
//	/************************************************************************/
//	int* take = new int[num];
//
//	int** step = new int*[num];
//	for (int i = 0; i < num; ++i)
//		step[i] = new int[len];
//
//	//step是一个 num*len的数组 step[k（ij）] 表示ij那个节点不能通过的word中的index 
//	for (int i = 0; i < num; ++i)
//	{
//		take[i] = 0;
//
//		for (int j = 0; j < len; ++j)
//			step[i][j] = 1;	//等于0表示 无法通过  1表示可以通过
//	}
//
//	bool exit = false;
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			exit = exitStr(board, i, j, step, take, word, 0);
//
//			if (exit)	break;
//		}
//
//		if (exit)	break;
//	}
//
//	//清理内存
//	for (int i = 0; i < num; ++i)
//		delete[] step[i];
//
//	delete[] step;
//
//	delete[] take;
//
//	return exit;
//}

bool dfs(vector<vector<char>> &board, int m, int n, int i, int j, string &word, int size, int index, int** step)
{
	if (index >= size)
		return true;

	if (i < 0 || j < 0 || i >= m || j >= n)
		return false;

	if (1 == step[i][j])
		return false;

	if (board[i][j] != word[index])
		return false;

	step[i][j] = 1;

	bool exit = 
		dfs(board, m, n, i - 1, j, word, size, index + 1, step) ||
		dfs(board, m, n, i, j + 1, word, size, index + 1, step) ||
		dfs(board, m, n, i + 1, j, word, size, index + 1, step) ||
		dfs(board, m, n, i, j - 1, word, size, index + 1, step);

	step[i][j] = 0;

	return exit;
}

bool exist(vector<vector<char>> &board, string word)
{
	const int m = board.size();
	const int n = board[0].size();

	//vector<vector<bool>> step(m, vector<bool>(n, false));
	int** step = new int*[m];
	for (int i = 0; i < m; ++i)
		step[i] = new int[n];

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			step[i][j] = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (dfs(board, m, n, i, j, word, word.size(), 0, step))
				return true;
		}
	}

	return false;
}

int main()
{
	vector<vector<char>> board;
	vector<char> re;
	re.push_back('a');
	re.push_back('a');
	board.push_back(re);

	bool b =exist(board, "aa");

	cout << b << endl;

	return 1;
}