#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) 
{
	int size = nums.size();

	if (0 == size)
		return 0;

	if (1 == size)
		return nums[0];

	//ÇÀ½ÙµÚÒ»¼Ò
	int y_r = nums[0];
	int y_n = 0;
	int y_t;

	int n_r = 0;
	int n_n = 0;
	int n_t;

	int t;
	for (int i = 1; i < size; ++i)
	{
		y_t = y_r;
		y_r = y_n + nums[i];
		y_n = max(y_t, y_n);

		n_t = n_r;
		n_r = n_n + nums[i];
		n_n = max(n_t, n_n);
	}

	return max(y_n, max(n_r, n_n));
}

int main()
{
	return 0;
}