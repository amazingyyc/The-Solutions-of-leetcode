#include <iostream>

using namespace std;

int calculate(string s) 
{
	int res = 0;

	int sign = 1;
	int temp_sign = 1;
	int temp = 1;
	int num = 0;

	for (auto c : s)
	{
		if ('+' == c || '-' == c)
		{
			if (1 == temp_sign)
				temp *= num;
			else
				temp /= num;

			res += sign * temp;

			temp = 1;
			num  = 0;

			temp_sign = 1;
			sign = '+' == c ? 1 : -1;
		}
		else if ('*' == c || '/' == c)
		{
			if (1 == temp_sign)
				temp *= num;
			else
				temp /= num;

			num = 0;
			temp_sign = '*' == c ? 1 : -1;
		}
		else if ('0' <= c && c <= '9')
		{
			num = num * 10 + c - '0';
		}
	}

	if (1 == temp_sign)
		temp *= num;
	else
		temp /= num;

	res += sign * temp;

	return res;
}

int main()
{
	cout << calculate("3+5 / 2 ") << endl;


	return 0;
}