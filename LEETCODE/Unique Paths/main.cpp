#include <iostream>

using namespace std;

/************************************************************************/
/* 
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
/************************************************************************/

int uniquePaths(int m, int n) 
{
	//if (0 >= m || 0 >= n)	return -1;
	//if (1 == m || 1 == n)	return 1;

	int num = m *n;

	int *paths = new int[num];

	paths[0] = 1;

	for (int i = 1; i < num; ++i)
	{
		int down  = (0 < i / n) ? paths[i - n] : 0;
		int right = (0 < i % n) ? paths[i - 1] : 0;

		paths[i] = down + right;
	}

	int path = paths[num - 1];

	delete[] paths;

	return path;
}

int main()
{
	int p = uniquePaths(3, 7);

	return 1;
}