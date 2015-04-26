#include <iostream>

using namespace std;

//²Î¿¼http://www.cnblogs.com/ganganloveu/p/4193373.html

int trailingZeroes(int n) 
{
	if (0 >= n)	return 0;

	int re = 0;

	while (n)
	{
		re += n / 5;

		n /= 5;
	}

	return re;
}

int main()
{
	trailingZeroes(2147483647);

	return 1;
}