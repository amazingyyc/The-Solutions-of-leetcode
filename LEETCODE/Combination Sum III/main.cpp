#include <iostream>
#include <vector>

using namespace std;

void test(int pre, int k, int n, vector<int>& cur, int sum, vector<vector<int>>& res)
{
	if (n == sum && k == cur.size())
		res.push_back(cur);
	
	if (sum >= n || cur.size() >= k)
		return;

	for (int i = pre + 1; i < 10; ++i)
	{
		cur.push_back(i);

		test(i, k, n, cur, sum + i, res);

		cur.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n) 
{
	vector<vector<int>> res;
	vector<int> cur;

	test(0, k, n, cur, 0, res);

	return res;
}

int main()
{
	combinationSum3(3, 9);

	return 0;
}