#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(const vector<vector<int>>& matrix, int target)
{
	if (0 == matrix.size())
		return false;

	if (0 == matrix[0].size())
		return false;

	int row = matrix.size();
	int line = matrix[0].size();
	int size = row * line;
	int l = 0;
	int r = size - 1;

	while (l <= r)
	{
		int m = (l + r) / 2;

		int mid = matrix[m / line][m % line];

		if (mid == target)
			return true;
		else if (mid > target)
			r = m - 1;
		else
			l = m + 1;
	}

	return false;
}

int main()
{


	return 1;
}