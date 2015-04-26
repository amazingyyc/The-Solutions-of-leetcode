#include <iostream>

using namespace std;

/*
允许至多两次重复
*/
int removeDuplicates(int A[], int n)
{
	if (0 == n)
		return n;

	int index = 0;
	bool count = false;	//是否已经重复

	for (int i = 1; i < n; ++i)
	{
		if (A[index] == A[i])
		{
			//如果相等
			if (!count)
			{
				count = true;

				if ((index + 1) != i)
					A[++index] = A[i];
				else
					index++;
			}
		}
		else
		{
			count = false;

			if ((index + 1) != i)
				A[++index] = A[i];
			else
				index++;
		}
	}

	return index + 1;
}

int main()
{
	int A[6] = {1, 1, 1, 2, 2, 3};

	int len = removeDuplicates(A, 6);

	return 1;
}