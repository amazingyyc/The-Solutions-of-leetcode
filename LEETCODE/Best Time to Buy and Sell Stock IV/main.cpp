#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int maxProfit(int k, vector<int> &prices) 
{
	int n = prices.size();
	if (2 > n) return 0;

	if (k > n / 2)
	{
		int sum = 0;
		for (int i = 1; i < n; ++i)
			sum += max(prices[i] - prices[i - 1], 0);

		return sum;
	}
	
	int* hold = new int[k + 1];
	int* sele = new int[k + 1];

	for (int i = 0; i <= k; ++i)
	{
		hold[i] = INT_MIN;
		sele[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		if (i >= 1)
		{
			hold[0] = max(hold[0], -1 * prices[i - 1]);
		}

		for (int j = 1; j <= k; ++j)
		{
			sele[j] = max(sele[j], hold[j - 1] + prices[i]);
			hold[j] = max(hold[j], sele[j] - prices[i]);
		}
	}
	

	return sele[k];
}*/

int maxProfit(int k, vector<int> &prices)
{
	int n = prices.size();
	if (2 > n) return 0;

	if (k > n / 2)
	{
		int sum = 0;
		for (int i = 1; i < n; ++i)
			sum += max(prices[i] - prices[i - 1], 0);

		return sum;
	}

	int* dp[2];
	dp[0] = new int[n];
	dp[1] = new int[n];

	for (int i = 0; i < n; ++i)
	{
		dp[0][i] = 0;
		dp[1][i] = 0;
	}

	for (int j = 1; j <= k; ++j)
	{
		int cur_max = INT_MIN;
		dp[j % 2][0] = 0;

		for (int i = 0; i < n; ++i)
		{
			dp[j % 2][i] = max(max(dp[j % 2][i - 1], dp[(j + 1) % 2][i]), prices[i] + cur_max);
			cur_max = max(cur_max, dp[(j+1)%2][i - 1] - prices[i]);
		}
	}

	return dp[k % 2][n - 1];
}

int main()
{
	vector<int> prices;
	prices.push_back(3);
	prices.push_back(3);
	prices.push_back(5);
	prices.push_back(0);
	prices.push_back(0);
	prices.push_back(3);
	prices.push_back(1);
	prices.push_back(4);

	maxProfit(2, prices);

	return 0;
}