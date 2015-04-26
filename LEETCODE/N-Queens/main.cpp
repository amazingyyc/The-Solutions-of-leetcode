#include <iostream>
#include <vector>

using namespace std;

//level表示到达第几行 list表示当前有哪些列已经被占用
//str一个参数 所有的字符均为'.'
//cur上一层所在的列
vector<vector<string>> getVectors(int n, int level, int* list, int* left, int* right, string str)
{
	vector<vector<string>> result;

	//level表示行号
	if (n == level)
	{
		result.push_back(vector<string>());

		return result;
	}

	for (int i = 0; i < n; ++i)
	{
		if (list[i] || left[n - 1 - level + i] || right[2*n - 2 - level - i])	
			continue;

		list[i] = 1;
		left[n - 1 - level + i] = 1;
		right[2 * n - 2 - level - i] = 1;

		vector<vector<string>> temp = getVectors(n, level + 1, list, left, right, str);
		string s = str;
		s[i] = 'Q';

		for (int j = 0; j < temp.size(); ++j)
		{
			temp[j].push_back(s);
			result.push_back(temp[j]);
		}

		list[i] = 0;
		left[n - 1 - level + i] = 0;
		right[2 * n - 2 - level - i] = 0;
	}

	return result;
}

vector<vector<string> > solveNQueens(int n) 
{
	//list对应与列 left对应与左倾 right对应与右倾  (i,j) left[n-1-i+j] right[2n-2-i-j]
	int* list = (int*)malloc(sizeof(int)*n);
	int* left = (int*)malloc(sizeof(int)*(2 * n - 1));
	int* right = (int*)malloc(sizeof(int)*(2 * n - 1));

	for (int i = 0; i < n; ++i)
		list[i] = 0;

	for (int i = 0; i < 2*n - 1; ++i)
		left[i] = right[i] = 0;

	string str(n, '.');

	vector<vector<string>> result = getVectors(n, 0, list, left, right, str);

	free(list);
	free(left);
	free(right);

	return result;
}

int main()
{
	vector<vector<string>> result = solveNQueens(6);

	cout << result.size() << endl;

	return 1;
}