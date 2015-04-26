#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) 
{
	int sum = 0;
	int start = 0;

	prices.push_back(INT_MIN);
	int size = prices.size();
	for (int i = 1; i < size; ++i)
	{
		if (prices[i] < prices[i - 1])
		{
			if (start == i - 1)
				start++;
			else
			{
				sum += prices[i - 1] - prices[start];

				start = i;
			}
		}
	}

	return sum;
}

int main()
{
	vector<int> p;
	p.push_back(5);
	p.push_back(2);
	p.push_back(3);
	p.push_back(2);
	p.push_back(6);
	p.push_back(6);
	p.push_back(2);
	p.push_back(9);
	p.push_back(1);
	p.push_back(0);
	p.push_back(7);
	p.push_back(4);
	p.push_back(5);
	p.push_back(0);

	maxProfit(p);

	return 1;
}