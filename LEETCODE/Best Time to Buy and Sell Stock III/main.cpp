#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
/*int maxProfit(vector<int> &prices, int l, int r)
{
	if (l >= r)	return 0;

	int profit = 0;
	int start = l;
	for (int i = l + 1; i <= r; ++i)
	{
		if (prices[i] < prices[i - 1])
		{
			if (start == i - 1)
				start = i;
			else
			{
				profit = max(profit, prices[i - 1] - prices[start]);
				start = (prices[start] >= prices[i]) ? i : start;
			}
		}
		else if(i == r)
			profit = max(profit, prices[i] - prices[start]);
	}

	return profit;
}

int maxProfit(vector<int> &prices) 
{
	int profit = 0;
	int size = prices.size();
	int start = 0;
	for (int i = 1; i < size; ++i)
	{
		if (prices[i] < prices[i - 1])
		{
			if (start == (i - 1))
				start = i;
			else
			{
				int temp = prices[i - 1] - prices[start] + maxProfit(prices, i, size - 1);
				profit = max(profit, temp);

				start = (prices[start] >= prices[i]) ? i : start;
			}
		}
		else if(i == (size - 1))
			profit = max(profit, prices[i] - prices[start]);
	}

	return profit;
}*/

int maxProfit(vector<int> &prices)
{
	int size = prices.size();
	if (2 > size)	return 0;

	int* f = new int[size];
	int* g = new int[size];

	f[0] = 0;
	int start = prices[0];

	for (int i = 1; i < size; ++i)
	{
		start = min(start, prices[i]);

		f[i] = max(f[i - 1], prices[i] - start);
	}

	g[size - 1] = 0;
	start = prices[size - 1];
	for (int i = size - 2; i >= 0; --i)
	{
		start = max(start, prices[i]);

		g[i] = max(g[i + 1], start - prices[i]);
	}

	int profix = INT_MIN;

	for (int i = 0; i < size; ++i)
	{
		profix = max(profix, f[i] + g[i + 1]);
	}

	delete[] f;
	delete[] g;

	return profix;
}

int main()
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(4);
	prices.push_back(2);
	prices.push_back(5);
	prices.push_back(7);
	prices.push_back(2);
	prices.push_back(4);
	prices.push_back(9);
	prices.push_back(0);

	maxProfit(prices);

	return 1;
}