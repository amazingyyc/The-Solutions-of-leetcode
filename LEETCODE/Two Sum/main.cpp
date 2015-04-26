#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) 
{
	vector<int> result;
	unordered_map<int, int> map;

	int size = numbers.size();
	for (int i = 0; i < size; ++i)
	{
		int temp = target - numbers[i];
		auto pos = map.find(temp);

		if (pos != map.end())
		{
			int j = (*pos).second;

			result.push_back(j + 1);
			result.push_back(i + 1);

			break;
		}
		else
			map[numbers[i]] = i;
	}

	return result;
}

int main()
{
	return 1;
}