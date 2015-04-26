#include <iostream>

using namespace std;

bool isNumber(string s) 
{
	int size = s.size();
	int l = 0;
	int r = size - 1;

	while (l < size && ' ' == s[l]) l++;
	while (r >= 0 && ' ' == s[r]) r--;

	if (l > r)	return false;

	//去除前面的符号
	if ('-' == s[l] || '+' == s[l])	l++;
	if ('-' == s[l] || '+' == s[l] || 'e' == s[l] || 'E' == s[l])
		return false;

	int pot = -1;	//'.'的位置 
	int sign = -1;	//'+'或者'-'位置
	int e = -1;	//'e'的位置

	for (int i = l; i <= r; ++i)
	{
		if ('.' == s[i])
		{
			if (-1 == pot)
				pot = i;
			else
				return false;
		}
		else if ('+' == s[i] || '-' == s[i])
		{
			if (-1 == sign)
				sign = i;
			else
				return false;
		}
		else if ('e' == s[i] || 'E' == s[i])
		{
			if (-1 == e)
				e = i;
			else
				return false;
		}
		else if (!('0' <= s[i] && s[i] <= '9'))
			return false;
	}

	if (-1 != e)
	{
		if (e == r || sign == r)
			return false;

		if (pot >= e || (pot == e - 1 && pot == l))
			return false;

		if (-1 != sign && sign != (e + 1))
			return false;
	}
	else
	{
		if (-1 != sign)
			return false;

		if (pot == l && pot == r)
			return false;
	}

	return true;
}

int main()
{
	//bool b1 = isNumber("0");
	bool b2 = isNumber(" 0.1 ");
	//bool b3 = isNumber("abc");
	//bool b4 = isNumber("1 a");
	//bool b5 = isNumber("2e10");

	//cout << b1 << endl;
	cout << b2 << endl;
	//cout << b3 << endl;
	//cout << b4 << endl;
	//cout << b5 << endl;

	return 1;
}