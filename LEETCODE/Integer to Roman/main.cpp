#include <iostream>

using namespace std;

/************************************************************************/
/* Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.                                                                     */
/************************************************************************/

string intToRoman(int num)
{
	/*string unit[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	string deca[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	string hund[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	string thun[4] = { "", "M", "MM", "MMM" };*/

	string unit[4][10] = 
	{
		{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		{ "", "M", "MM", "MMM" }
	};

	string re = "";
	int u = 0;

	while (num)
	{
		int rema = num % 10;

		re = unit[u++][rema] + re;

		num = num / 10;
	}

	return re;
}

int main()
{
	return 1;
}