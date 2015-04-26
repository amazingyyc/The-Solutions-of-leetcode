#include <iostream>
#include <string>

using namespace std;

/************************************************************************/
/* Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.                                                                     */
/************************************************************************/

int romanToInt(string s) 
{
	string unit[4][10] =
	{
		{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		{ "", "M", "MM", "MMM",   "", "",  "",   "",    "",      "" }
	};

	int num = 0;
	int u = 0;
	int t = 1;

	while ("" != s)
	{
		int index = 0;
		int index_len = 0;

		for (int i = 1; i < 10; ++i)
		{
			if (unit[u][i] != "" && s.npos != s.find(unit[u][i]))
			{
				if (unit[u][i].size() > index_len)
				{
					index = i;
					index_len = unit[u][i].size();
				}
			}
		}

		num += index * t;

		s.assign(s, 0, s.size() - unit[u][index].size());

		u++;
		t *= 10;
	}

	return num;
}

int main()
{
	int num = romanToInt("DCXXI");

	return 1;
}