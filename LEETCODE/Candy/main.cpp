#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int candy(vector<int> &ratings) 
{
	ratings.push_back(INT_MAX);
	int n = ratings.size();

	if (1 == n)	return 0;
	if (2 == n) return 1;

	vector<int> candy(n, 1);

	int peak = 0;
	int cur = 1;

	for (int i = 1; i < n; ++i)
	{
		if (ratings[i] == ratings[i - 1])
		{
			if (peak == i - 1)
			{
				peak = i;
				candy[i] = 1;
				cur = 1;
			}
		}
		else if (ratings[i] > ratings[i - 1])
		{
			if (peak == i - 1)
			{
				peak = i;
				candy[i] = ++cur;
			}
			else
			{
				cur = 1;

				for (int j = i - 1; j > peak; --j)
				{
					if (j < i - 1 && ratings[j] == ratings[j + 1])
						cur = 1;

					candy[j] = cur++;
				}

				candy[peak] = max(candy[peak], cur);

				cur = 1;
				peak = i - 1;
				i--;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < n - 1; ++i)
		sum += candy[i];

	return sum;
}*/

//×óÓÒ¸öÉ¨ÃèÒ»±ß
int candy(vector<int> &ratings)
{
	int n = ratings.size();

	vector<int> candy(n, 1);

	int cur = 1;

	for (int i = 1; i < n; ++i)
	{
		if (ratings[i] > ratings[i - 1])
			candy[i] = ++cur;
		else
			cur = 1;
	}

	int sum = candy[n - 1];

	cur = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
			candy[i] = max(++cur, candy[i]);
		else
			cur = 1;

		sum += candy[i];
	}


	return sum;
}



int main()
{
	vector<int> ratings;
	ratings.push_back(5);
	ratings.push_back(1);
	ratings.push_back(1);
	ratings.push_back(1);
	ratings.push_back(10);
	ratings.push_back(2);
	ratings.push_back(1);
	ratings.push_back(1);
	ratings.push_back(1);
	ratings.push_back(3);

	candy(ratings);

	return 1;
}