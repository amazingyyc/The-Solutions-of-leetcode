#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Data
{
	int up;
	int left;
	int square;
};

int maximalSquare(vector<vector<char>>& matrix) 
{
	int n = matrix.size();
	if (0 == n)	return 0;
	int m = matrix[0].size();
	if (0 == m)	return 0;

	int max_square = INT_MIN;
	vector<vector<Data>> datas(n, vector<Data>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			//char c = matrix[i][j];
			int add = ('1' == matrix[i][j]) ? 1 : 0;

			if (0 == i && 0 == j)
			{
				datas[i][j].up     = add;
				datas[i][j].left   = add;
				datas[i][j].square = add;
			}
			else if (0 == i)
			{
				datas[i][j].up = add;
				datas[i][j].left = (1 == add) ? datas[i][j - 1].left + 1 : 0;
				datas[i][j].square = add;
			}
			else if (0 == j)
			{
				datas[i][j].up = (1 == add)? datas[i - 1][j].up + 1 : 0;
				datas[i][j].left = add;
				datas[i][j].square = add;
			}
			else
			{
				datas[i][j].up = (1 == add) ? datas[i - 1][j].up + 1 : 0;
				datas[i][j].left = (1 == add) ? datas[i][j - 1].left + 1 : 0;
				datas[i][j].square = min(datas[i - 1][j - 1].square + 1, min(datas[i][j].up, datas[i][j].left));
			}

			max_square = max(max_square, datas[i][j].square);
		}
	}
		
	return max_square*max_square;
}

int main()
{
	return 0;
}