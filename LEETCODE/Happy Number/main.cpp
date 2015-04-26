#include <iostream>
#include <unordered_set>

using namespace std;

/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
/*int sum(int n)
{
	int sum = 0;
	while (n)
	{
		int rem = n % 10;

		sum += rem * rem;

		n /= 10;
	}

	return sum;
}

bool isHappy(int n) 
{
	if (0 >= n) return false;

	unordered_set<int> sets;

	while (1 != n)
	{
		if (sets.find(n) != sets.end())
			return false;

		sets.insert(n);

		n = sum(n);
	}

	return true;
}*/

int sum(int n)
{
	int sum = 0;
	while (n)
	{
		int rem = n % 10;
		sum += rem * rem;
		n /= 10;
	}

	return sum;
}

bool isHappy(int n)
{
	int A = sum(n);
	int B = sum(A);

	while (1 != A && A != B)
	{
		A = sum(A);
		B = sum(sum(B));
	}

	return A == 1;
}

int main()
{
	isHappy(7);

	return 1;
}