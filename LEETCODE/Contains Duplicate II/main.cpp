#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
	unordered_set<int> set;

	int i = 0;
	int j = 0;
	int size = nums.size();

	for (; j < size; ++j)
	{
		if (j - i > k)
			set.erase(nums[i++]);

		if (set.find(nums[j]) != set.end())
			return true;

		set.insert(nums[j]);
	}

	return false;
}

int main()
{
	return 0;
}