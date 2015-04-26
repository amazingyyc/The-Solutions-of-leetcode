#include <iostream>
#include <vector>

using namespace std;

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/

vector<vector<int> > generate(int numRows) 
{
	vector<vector<int>> result;

	for (int i = 0; i < numRows; ++i)
	{
		vector<int> temp;

		for (int j = 0; j <= i; ++j)
		{
			if (0 == j || j == i)
				temp.push_back(1);
			else
				temp.push_back(result[i-1][j - 1] + result[i-1][j]);
		}

		result.push_back(temp);
	}

	return result;
}

int main()
{
	generate(3);

	return 1;
}