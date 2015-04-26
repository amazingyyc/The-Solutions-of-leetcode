#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/
/************************************************************************/

vector<vector<int> > generateMatrix(int n) 
{
	vector<vector<int>> result;

	if (0 == n)	return result;

	for (int i = 0; i < n; ++i)
		result.push_back(vector<int>(n));

	int num = 1;
	int circle = 0;
	int direct = 0;

	while (1)
	{
		switch (direct)
		{
		case 0:
		{
				  //vector<int> vec = result[circle];
				  int row = circle;
				  for (int i = circle; i < n - circle; ++i)
				  {
					  result[row][i] = num++;

					  if (num > n*n)	return result;
				  }

				  break;
		}
		case 1:
		{
				  int list = n - circle - 1;
				  for (int i = circle + 1; i < n - circle; ++i)
				  {
					  result[i][list] = num++;

					  if (num > n*n)	return result;
				  }

				  break;
		}
		case 2:
		{
				  int row = n - circle - 1;
				  for (int i = n - circle - 2; i >= circle; --i)
				  {
					  result[row][i] = num++;

					  if (num > n*n)	return result;
				  }

				  break;
		}
		case 3:
		{
				  int list = circle;
				  for (int i = n - circle - 2; i >= circle + 1; --i)
				  {
					  result[i][list] = num++;

					  if (num > n*n)	return result;
				  }

				  circle++;

				  break;
		}
		default:
			break;
		}

		direct = (direct + 1) % 4;
	}
}

int main()
{
	vector<vector<int>> result = generateMatrix(3);

	return 1;
}