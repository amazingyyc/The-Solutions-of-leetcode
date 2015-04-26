#include <iostream>
#include <stdint.h>

using namespace std;

int hammingWeight(uint32_t n) 
{
	int num = 0;

	while (n)
	{
		num++;

		n &= n - 1;
	}

	return num;
}

int main()
{
	hammingWeight(4);

	return 1;
}