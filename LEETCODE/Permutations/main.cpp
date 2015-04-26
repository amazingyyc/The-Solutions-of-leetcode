#include <iostream>
#include <vector>

using namespace std;

//n：剩余的个数最大为num.size order标记是否已经使用 size数组长度
vector<vector<int>> getVectors(vector<int> &num, int size, int n, int* order)
{
	vector<vector<int>> result;

	if (0 == n)
	{
		result.push_back(vector<int>());

		return result;
	}

	for (int i = 0; i < size; ++i)
	{
		if (1 == order[i])	continue;

		order[i] = 1;

		vector<vector<int>> temp = getVectors(num, size, n - 1, order);

		int tSize = temp.size();
		for (int j = 0; j < tSize; ++j)
		{
			temp[j].insert(temp[j].begin(), num[i]);

			result.push_back(temp[j]);
		}

		order[i] = 0;
	}

	return result;
}

vector<vector<int>> permute(vector<int> &num) 
{
	int size = num.size();
	int* order = (int *)malloc(sizeof(int)* size);

	for (int i = 0; i < size; ++i)
		order[i] = 0;

	vector<vector<int>> result = getVectors(num, size, size, order);

	free(order);

	return result;
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	permute(num);

	return 1;
}