#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/************************************************************************/
/* 
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
/************************************************************************/

//维护一个上升的栈
int maxProfit(vector<int> &prices) 
{
	if (0 == prices.size())	return 0;

	prices.push_back(INT_MIN);

	int profit = 0;
	int start = 0;
	int size = prices.size();
	for (int i = 1; i < size; ++i)
	{
		if (prices[i] <= prices[i - 1])
		{
			int temp = prices[i - 1] - prices[start];

			if (temp > profit)
				profit = temp;

			if (prices[i] < prices[start])
				start = i;
		}
	}

	return profit;
}


int main()
{
	return 1;
}