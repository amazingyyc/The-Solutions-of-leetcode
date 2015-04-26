#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//递归求出所有结果 start从cans的第start开始进行求解 
vector<vector<int>> getVectors(vector<int> &cans, int start, int target)
{
	vector<vector<int>> result;

	//if (start >= cans.size() || target < 0)
		//return result;

	if (0 == target)
	{
		vector<int> re;
		result.push_back(re);

		return result;
	}

	int size = cans.size();
	for (int i = start; i < size; ++i)
	{
		if (i > start && cans[i] == cans[i-1])
			continue;

		int cur = cans[i];

		if (cur > target)	return result;

		vector<vector<int>> temp = getVectors(cans, i + 1, target - cur);

		int tSize = temp.size();
		for (int j = 0; j < tSize; ++j)
		{
			temp[j].insert(temp[j].begin(), cur);
			result.push_back(temp[j]);
		}
	}

	return result;
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) 
{
	vector<vector<int>> result;

	if (num.empty())	return result;

	sort(num.begin(), num.end());

	result = getVectors(num, 0, target);

	return result;
}

int main()
{
	vector<int> can;
	can.push_back(1);
	/*can.push_back(10);
	can.push_back(1);
	can.push_back(2);
	can.push_back(7);
	can.push_back(6);
	can.push_back(1);
	can.push_back(5);*/

	combinationSum2(can, 1);

	return 1;
}