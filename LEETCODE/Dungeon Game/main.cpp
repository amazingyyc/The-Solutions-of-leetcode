#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int calculateMinimumHP(vector<vector<int>> &dungeon) 
{
	int m = dungeon.size();
	int n = dungeon[0].size();

	vector<vector<int>> health(m, vector<int>(n, 0));	//经过i j的所需要的最小health
	vector<vector<int>> sums(m, vector<int>(n, 0)); //到ij最小路径所经过的之和的最大值

	for (int i = 0; i < m; ++i)
	for (int j = 0; j < n; ++j)
	{
		if (0 == i && 0 == j)
		{
			sums[i][j] = dungeon[0][0];
			health[i][j] = (0 > sums[i][j]) ? 1 - sums[i][j] : 1;
		}
		else if (0 == i)
		{
			sums[i][j] = sums[i][j - 1] + dungeon[i][j];
			health[i][j] = max(health[i][j - 1], 1 - sums[i][j]);
		}
		else if (0 == j)
		{
			sums[i][j] = sums[i - 1][j] + dungeon[i][j];
			health[i][j] = max(health[i - 1][j], 1 - sums[i][j]);
		}
		else
		{
			int upSum = sums[i - 1][j] + dungeon[i][j];
			int leftSum = sums[i][j - 1] + dungeon[i][j];

			int upHealth = max(health[i - 1][j], 1 - upSum);
			int leftHealth = max(health[i][j-1], 1 - leftSum);

			sums[i][j] = max(upSum, leftSum);

			health[i][j] = min(upHealth, leftHealth);
		}
	}

	int re = health[m - 1][n - 1];

	return re;
}*/

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
	int m = dungeon.size();
	int n = dungeon[0].size();

	vector<int> health(n + 1, INT_MAX);
	health[n-1] = 1;

	for (int i = m - 1; i >= 0; --i)
	for (int j = n - 1; j >= 0; --j)
	{
		int need = min(health[j + 1], health[j]) - dungeon[i][j];
		health[j] = (0 < need) ? need : 1;
	}

	return health[0];
}

int main()
{

	vector<vector<int>> dungeon;
	vector<int> d1;
	//d1.push_back(-2);
	d1.push_back(-3);
	//d1.push_back(-7);

	vector<int> d2;
	d2.push_back(-7);
	//d2.push_back(-10);
	//d2.push_back(1);

	//vector<int> d3;
	//d3.push_back(10);
	//d3.push_back(30);
	//d3.push_back(-5);

	dungeon.push_back(d1);
	dungeon.push_back(d2);
	//dungeon.push_back(d3);

	calculateMinimumHP(dungeon);

	return 0;
}