#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) 
{
	//四个方向0向右 1向下 2向左 3向上 
	int direct = 0;
	vector<int> result;
	while (!matrix.empty() && !matrix[0].empty())
	{
		switch (direct)
		{
		case 0:
		{
				  vector<int> first = matrix[0];
				  matrix.erase(matrix.begin());

				  for (int i = 0; i < first.size(); ++i)
					  result.push_back(first[i]);

				  break;
		}
		case 1:
		{
				  int m = matrix.size();
				  int n = matrix[0].size();

				  for (int i = 0; i < m; ++i)
				  {
					  result.push_back(matrix[i][n - 1]);

					  matrix[i].pop_back();
				  }
				  break;
		}
			
		case 2:
		{
				  vector<int> last = matrix[matrix.size() - 1];
				  matrix.pop_back();

				  for (int i = last.size() - 1; i >= 0; --i)
					  result.push_back(last[i]);

				  break;
		}
		case 3:
		{
			int m = matrix.size();

			for (int i = m - 1; i >= 0; --i)
			{
				result.push_back(matrix[i][0]);

				matrix[i].erase(matrix[i].begin());
			}

			break;
		}
			
		default:
			break;
		}

		direct = (direct + 1) % 4;
	}

	return result;
}

int main()
{
	vector<vector<int>> matrix;
	vector<int> s;
	s.push_back(1);


	matrix.push_back(s);

	spiralOrder(matrix);

	return 1;
}