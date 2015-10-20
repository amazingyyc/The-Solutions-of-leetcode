#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
	long data;
	int index;
};

static bool cmp(Node n1, Node n2)
{
	return n1.data < n2.data;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
	int size = nums.size();

	if (0 == k || 0 == size || 1 == size)
		return false;

	vector<Node> nodes(size);
	for (int i = 0; i < size; ++i)
	{
		nodes[i].index = i;
		nodes[i].data = nums[i];
	}

	//ÅÅÐò
	sort(nodes.begin(), nodes.end(), cmp);

	int i = 0;
	int j = 1;
	
	while (j < size)
	{
		while (j < size && nodes[j].data - nodes[i].data > t)
		{
			if (i < j - 1)
				i++;
			else
			{
				i++;
				j++;
			}
		}

		if (j >= size)
			break;

		if (abs(nodes[j].index - nodes[i].index) <= k)
			return true;

		if (j == size - 1 && i < j - 1)
			i++;
		else
			j++;
	}

	return false;
}

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(-2);
	nums.push_back(2);

	containsNearbyAlmostDuplicate(nums, 2, 1);

	return 0;
}