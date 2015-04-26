#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int numIslands(vector<vector<char>> &grid) 
{
	int m = grid.size();
	if (0 == m)	return 0;
	int n = grid[0].size();
	if (0 == n) return 0;

	int count = 0;

	stack<int> stac;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ('0' == grid[i][j])
				continue;

			count++;

			stac.push(j);
			stac.push(i);

			while (!stac.empty())
			{
				int r = stac.top();
				stac.pop();
				int c = stac.top();
				stac.pop();

				grid[r][c] = '0';

				if (r > 0 && '1' == grid[r - 1][c])
				{
					stac.push(c);
					stac.push(r - 1);
				}
				if (c < n - 1 && '1' == grid[r][c + 1])
				{
					stac.push(c + 1);
					stac.push(r);
				}
				if (r < m - 1 && '1' == grid[r + 1][c])
				{
					stac.push(c);
					stac.push(r + 1);
				}
				if (c > 0 && '1' == grid[r][c - 1])
				{
					stac.push(c - 1);
					stac.push(r);
				}
			}
		}
	}

	return count;
}

int main()
{
	vector<vector<char>> grid;
	vector<char> vec;
	vec.push_back('1');
	vec.push_back('0');

	grid.push_back(vec);

	numIslands(grid);

	return 1;
}