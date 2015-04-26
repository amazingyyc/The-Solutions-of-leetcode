#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].                                                                    
*/
/************************************************************************/

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

		bool have = false;

		for (int j = 0; j < i; ++j)
		{
			if (0 == order[j] && num[j] == num[i])
			{
				have = true;

				break;
			}
		}

		if (have)	continue;

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

vector<vector<int> > permuteUnique(vector<int> &num) 
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
	num.push_back(1);
	num.push_back(2);

	permuteUnique(num);

	return 1;
}