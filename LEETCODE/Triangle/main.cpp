#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) 
{
	int count = triangle.size();
	
	if (0 == count)	return 0;

	vector<vector<int>> result;
	for (int i = 1; i <= count; ++i)
	{
		result.push_back(vector<int>(i, 0));
	}

	result[0][0] = triangle[0][0];

	for (int i = 1; i < count; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (0 == j)
				result[i][j] = result[i - 1][j] + triangle[i][j];
			else if (i == j)
				result[i][j] = result[i - 1][j - 1] + triangle[i][j];
			else
				result[i][j] = min(result[i - 1][j - 1], result[i - 1][j]) + triangle[i][j];
		}
	}

	int sum = result[count - 1][0];
	for (int i = 1; i < count; ++i)
	{
		if (sum > result[count - 1][i])
			sum = result[count - 1][i];
	}

	return sum;
}

int main()
{
	return 1;
}