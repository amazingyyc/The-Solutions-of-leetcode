#include <iostream>
#include <vector>

using namespace std;

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

void setZeroes(vector<vector<int> > &matrix) 
{
	if (matrix.empty())	return;

	int m = matrix.size();
	int n = matrix[0].size();

	bool row = false;	//是否将第一行全设为0
	bool cul = false;	//是否将第一列全设为0

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (0 == matrix[i][j])
			{
				if (0 == i)	row = true;
				if (0 == j) cul = true;

				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (0 == matrix[i][0] || 0 == matrix[0][j])
				matrix[i][j] = 0;
		}
	}

	if (row)
	{
		for (int i = 0; i < n; ++i)
			matrix[0][i] = 0;
	}

	if (cul)
	{
		for (int i = 0; i < m; ++i)
			matrix[i][0] = 0;
	}
}

int main()
{
	return 1;
}