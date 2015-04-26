#include <iostream>

using namespace std;

int singleNumber(int A[], int n)
{
	int re = A[0];

	for (int i = 1; i < n; ++i)
		re ^= A[i];

	return re;
}

int main()
{


	return 1;
}