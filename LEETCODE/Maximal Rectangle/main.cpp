#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int getMaxRect(int *A, int n)
{
	stack<int> stac;
	int result = -1;

	for (int i = 0; i < n;)
	{
		if (stac.empty() || A[i] > A[stac.top()])
			stac.push(i++);
		else
		{
			//删除栈顶元素
			int top = stac.top();
			stac.pop();

			result = max(result, A[top] * (stac.empty() ? i : i - stac.top() - 1));
		}
	}

	return result;
}

int maximalRectangle(vector<vector<char> > &matrix) 
{
	if (matrix.empty())return 0;

	int m = matrix.size();
	int n = matrix[0].size();

	//left存储一个节点 包括自身的上面的最长长度
	int **up = new int *[m];
	for (int i = 0; i < m; ++i)
	{
		up[i] = new int[n + 1];

		//作为结尾
		up[i][n] = -1;
	}
		

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ('0' == matrix[i][j])
				up[i][j] = 0;
			else if (0 == i)
				up[i][j] = 1;
			else
				up[i][j] = up[i-1][j] + 1;
		}
	}

	int result = -1;
	for (int i = 0; i < m; ++i)
		result = max(result, getMaxRect(up[i], n + 1));

	for (int i = 0; i < m; ++i)
		delete[] up[i];

	delete[] up;

	return result;
}

int main()
{
	vector<char> vc;
	vc.push_back('0');
	vc.push_back('0');
	vc.push_back('0');
	//vc.push_back('1');

	vector<vector<char>> vvc;
	vvc.push_back(vc);
	vvc.push_back(vc);
	vvc.push_back(vc);
	vvc.push_back(vc);

	int re = maximalRectangle(vvc);

	cout << re << endl;

	return 1;
}