#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n) 
{
	if (0 == n)	return vector<int>(1, 0);

	vector<int> result(1 << n);

	result[0] = 0;
	result[1] = 1;

	int t, l, r;

	for (int i = 2, len = 2; i <= n; ++i, len = len << 1)
	{
		t = 1 << (i - 1);
		l = len;
		r = len;

		while (l)
		{
			result[r++] = result[--l] | t;
		}
	}

	return result;
}

int main()
{
	grayCode(3);

	return 1;
}