#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//void solve(vector<vector<char>> &board, int i, int j, int n, int m)
//{
//	if ('O' != board[i][j])	return;
//
//	queue<int> que;
//	que.push(i * n + j);
//
//	while (!que.empty())
//	{
//		int cur = que.front();
//		que.pop();
//		
//		int r = cur / n;
//		int c = cur % n;
//
//		board[r][c] = 'A';
//
//		if (r > 0 && 'O' == board[r - 1][c])
//			que.push((r - 1) * n + c);
//		if (c < n - 1 && 'O' == board[r][c + 1])
//			que.push(r * n + c + 1);
//		if (r < m - 1 && 'O' == board[r + 1][c])
//			que.push((r + 1)*n + c);
//		if (c > 0 && 'O' == board[r][c - 1])
//			que.push(r*n + c - 1);
//	}
//}
//
///*void visit(vector<vector<char>> &board, int i, int j, queue<int> &q) {
//	const int m = board.size();
//	const int n = board[0].size();
//	if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
//		return;
//	board[i][j] = 'A'; // 既有标记功能又有去重功能
//	q.push(i * n + j);
//}
//void bfs(vector<vector<char>> &board, int i, int j) {
//	queue<int> q;
//	visit(board, i, j, q);
//	while (!q.empty()) 
//	{
//		int cur = q.front(); 
//		q.pop();
//
//		int x = cur / board[0].size();
//		int y = cur % board[0].size();
//
//		visit(board, x - 1, y, q);
//		visit(board, x, y - 1, q);
//		visit(board, x + 1, y, q);
//		visit(board, x, y + 1, q);
//	}
//}*/
//
//
//void solve(vector<vector<char>> &board) 
//{
//	int m = board.size();
//	if (0 == m)	return;
//	int n = board[0].size();
//	if (0 == n) return;
//	if (1 == m || 1 == n)return;
//
//	for (int i = 0; i < n; ++i)
//	{
//		solve(board, 0, i, n, m);
//		solve(board, m - 1, i, n, m);
//		//bfs(board, 0, i);
//		//bfs(board, m - 1, i);
//	}
//
//	for (int i = 1; i < m - 1; ++i)
//	{
//		solve(board, i, 0, n, m);
//		solve(board, i, n - 1, n, m);
//		//bfs(board, i, 0);
//		//bfs(board, i, n - 1);
//	}
//
//	for (int i = 0; i < m; ++i)
//	for (int j = 0; j < n; ++j)
//	{
//		if ('O' == board[i][j])
//			board[i][j] = 'X';
//		else if ('A' == board[i][j])
//			board[i][j] = 'O';
//	}
//}

void solve(vector<vector<char>> &board, int i, int j, int n, int m)
{
	if ('O' != board[i][j])	return;

	board[i][j] = 'A';

	queue<int> que;
	que.push(i * n + j);

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		int r = cur / n;
		int c = cur % n;

		if (r > 0 && 'O' == board[r - 1][c])
		{
			board[r - 1][c] = 'A';
			que.push((r - 1) * n + c);
		}
		if (c < n - 1 && 'O' == board[r][c + 1])
		{
			board[r][c + 1] = 'A';
			que.push(r * n + c + 1);
		}
			
		if (r < m - 1 && 'O' == board[r + 1][c])
		{
			board[r + 1][c] = 'A';
			que.push((r + 1)*n + c);
		}
			
		if (c > 0 && 'O' == board[r][c - 1])
		{
			board[r][c - 1] = 'A';
			que.push(r*n + c - 1);
		}
	}
}

void solve(vector<vector<char>> &board)
{
	int m = board.size();
	if (0 == m)	return;
	int n = board[0].size();
	if (0 == n) return;
	if (1 == m || 1 == n)return;

	for (int i = 0; i < n; ++i)
	{
		solve(board, 0, i, n, m);
		solve(board, m - 1, i, n, m);
	}

	for (int i = 1; i < m - 1; ++i)
	{
		solve(board, i, 0, n, m);
		solve(board, i, n - 1, n, m);
	}

	for (int i = 0; i < m; ++i)
	for (int j = 0; j < n; ++j)
	{
		if ('O' == board[i][j])
			board[i][j] = 'X';
		else if ('A' == board[i][j])
			board[i][j] = 'O';
	}
}

	
int main()
{
	vector<string> board;
	board.push_back("OOOOOOOOXOOOOOXOOOOO");
	board.push_back("OOOOOOOXOOOOOOOOOOOO");
	board.push_back("XOOXOXOOOOXOOXOOOOOO");
	board.push_back("OOOOOOOOOOOOOOOOOXXO");
	board.push_back("OXXOOOOOOXOOOOOOOOOO");

	board.push_back("OOOOXOOOOOOXOOOOOXXO");

	board.push_back("OOOOOOOXOOOOOOOOOOOO");

	board.push_back("OOOOOOOOOOOOOXOOOOOO");

	board.push_back("OOOOOOOOOOOOOOOOOOXO");

	board.push_back("OOOOOXOOOOOOOOOOOOOO");

	board.push_back("OOOOOOOOXOOOOOOOOOOO");

	board.push_back("OOOOXOOOOXOOOOOOOOOO");

	board.push_back("OOOOOOOOXOOOOOOOOOOO");

	board.push_back("XOOOOOOOOXXOOOOOOOOO");

	board.push_back("OOOOOOOOOOOXOOOOOOOO");

	board.push_back("OOOOXOOOOOOOOXOOOOOX");

	board.push_back("OOOOOXOOOOOOOOOXOXOO");

	board.push_back("OXOOOOOOOOOOOOOOOOOO");

	board.push_back("OOOOOOOOXXOOOXOOXOOX");
	board.push_back("OOOOOOOOOOOOOOOOOOOO");

	solve(board);

	return 1;
}