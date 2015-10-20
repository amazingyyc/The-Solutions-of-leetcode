#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
	unordered_map<int, int> map;

	for (int key : nums)
	{
		if (map.find(key) != map.end())
			return true;

		map[key]++;
	}

	return false;
}

int main()
{
	return 0;
}