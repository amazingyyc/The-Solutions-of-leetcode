#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &grid) 
{
	int m = grid.size();
	int n = grid[0].size();

	if (grid[0][0] || grid[m - 1][n - 1])	return 0;

	int num = m*n;
	int *paths = new int[num];

	paths[0] = 1;

	for (int i = 1; i < num; ++i)
	{
		int r = i / n;	//ÐÐºÍÁÐ
		int l = i % n;

		if (1 == grid[r][l])
		{
			paths[i] = 0;

			continue;
		}

		int down = (0 < r) ? paths[i - n] : 0;
		int right = (0 < l) ? paths[i - 1] : 0;

		paths[i] = down + right;
	}

	int path = paths[num - 1];

	delete[] paths;

	return path;
}

int main()
{
	return 1;
}