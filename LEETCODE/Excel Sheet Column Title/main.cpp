#include <iostream>

using namespace std;

string convertToTitle(int n) 
{
	string re = "";
	int rem = 0;

	while (n)
	{
		rem = n % 26;
		n = n / 26;

		if (0 == rem)
		{
			n--;
			re = "Z" + re;
		}
		else
		{
			string temp = string(1, rem - 1 + 'A');
			re = temp + re;
		}
	}

	return re;
}

int main()
{
	convertToTitle(703);

	return 0;
}