#include <iostream>

using namespace std;

/************************************************************************/
/* 牛顿迭代法求平方根                                                                     */
/************************************************************************/

int sqrt(int a) 
{
	if (0 == a)	return 0;
	if (1 == a)	return 1;

	int x = a / 2;

	while (1)
	{
		int temp = (x + a / x) / 2;

		if (x <= temp)
			return x;
		else
			x = temp;
	}
}

int main()
{
	int s = sqrt(2147483647);
	cout << s << endl;

	return 1;
}