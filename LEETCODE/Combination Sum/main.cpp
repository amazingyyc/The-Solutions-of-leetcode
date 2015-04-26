#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//递归求出所有结果 start从cans的第start开始进行求解 
vector<vector<int>> getVectors(vector<int> &cans, int start, int target)
{
	vector<vector<int>> result;

	if (0 == target)
	{
		vector<int> re;
		result.push_back(re);

		return result;
	}

	int size = cans.size();
	for (int i = start; i < size; ++i)
	{
		int cur = cans[i];

		if (cur > target)	return result;

		vector<vector<int>> temp = getVectors(cans, i, target - cur);

		int tSize = temp.size();
		for (int j = 0; j < tSize; ++j)
		{
			temp[j].insert(temp[j].begin(), cur);
			result.push_back(temp[j]);
		}
	}

	return result;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) 
{
	vector<vector<int>> result;

	if (candidates.empty())	return result;

	//删除重复的元素
	sort(candidates.begin(), candidates.end());
	vector<int>::iterator it = candidates.begin() + 1;
	for (; it != candidates.end();)
	{
		if ((*it) == *(it - 1))
			it = candidates.erase(it);
		else
			++it;
	}

	result = getVectors(candidates, 0, target);

	return result;
}

int main()
{
	vector<int> can;
	can.push_back(8);
	can.push_back(7);
	can.push_back(4);
	can.push_back(3);
	//can.push_back(7);

	combinationSum(can, 11);

	return 1;
}