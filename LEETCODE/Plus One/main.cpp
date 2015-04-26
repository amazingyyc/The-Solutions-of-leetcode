#include <iostream>
#include <vector>

using namespace std;

/*
想一个高精度数中加1
*/
vector<int> plusOne(vector<int> &digits)
{
	int rem = 1;	//上次计算的余数 

	int size = digits.size();

	for (int i = size - 1; i >= 0 && 0 != rem; --i)
	{
		digits[i] += rem;

		rem = digits[i] / 10;
		digits[i] %= 10;
	}

	
	if (0 != rem)
		digits.insert(digits.begin(), rem);

	return digits;
}

int main()
{
	vector<int> digits;

	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);

	digits = plusOne(digits);

	return 1;
}