#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid) 
{
	int m = grid.size();
	int n = grid[0].size();
	int num = m*n;
	int* costs = new int[num];

	costs[0] = grid[0][0];
	for (int i = 1; i < num; ++i)
	{
		int r = i / n;	//ÐÐºÍÁÐ
		int l = i % n;

		int down = (0 < r) ? costs[i - n] : INT_MAX;
		int right = (0 < l) ? costs[i - 1] : INT_MAX;

		costs[i] = grid[r][l] + min(down, right);
	}

	int cost = costs[num - 1];

	delete[] costs;

	return cost;
}

int main()
{
	return 1;
}