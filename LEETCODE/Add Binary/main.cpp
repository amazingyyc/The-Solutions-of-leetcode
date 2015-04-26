#include <iostream>

using namespace std;

/*
二进制想加
*/
string addBinary(string a, string b)
{
	if (0 == a.size())	return b;
	if (0 == b.size())	return a;

	int ram = 0;
	string re = "";

	int aSize = a.size() - 1;
	int bSize = b.size() - 1;

	while (0 <= aSize || 0 <= bSize)
	{
		int aNum = (0 > aSize) ? 0 : ('0' == a[aSize] ? 0 : 1);
		int bNum = (0 > bSize) ? 0 : ('0' == b[bSize] ? 0 : 1);

		int num = ram + aNum + bNum;

		ram = num / 2;
		re = (0 == num % 2 ? "0" : "1") + re;

		aSize--;
		bSize--;
	}

	re = (0 == ram ? "" : "1") + re;

	return re;
}

int main()
{
	string re = addBinary("11", "1");

	return 1;
}