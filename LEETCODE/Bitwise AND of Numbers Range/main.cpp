#include <iostream>

using namespace std;

/*int rangeBitwiseAnd(int m, int n) 
{
	if (n == m) return n;

	int re = 0;
	for (int i = 0; i < 32 && m && n; ++i)
	{
		if ((m == n) && (1 & n))
			re |= (1 << i);

		m >>= 1;
		n >>= 1;
	}

	return re;
}*/

int rangeBitwiseAnd(int m, int n)
{
	int c = 0;

	while (m != n)
	{
		m >>= 1;
		n >>= 1;

		c++;
	}

	return n << c;
}

int main()
{
	cout << rangeBitwiseAnd(5, 7) << endl;

	return 1;
}