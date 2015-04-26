#include <iostream>

using namespace std;

double pw(double x, int n) 
{
	bool sign = false;

	if (n < 0)
	{
		sign = true;
		n = -n;
	}


	int k = 1;
	double multi = x;
	double result = 1.0;

	while (n > 0)
	{
		n -= k;
		result *= multi;

		if (k <= n / 2)
		{
			k = k + k;
			multi = multi*multi;
		}
		else if (k > n)
		{
			k = 1;
			multi = x;
		}
	}

	if (sign)
		return 1.0 / result;

	return result;
}

int main()
{
	double d = pw(11.0, -5);

	cout << d << endl;

	return 1;
}