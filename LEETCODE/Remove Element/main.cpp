#include <iostream>

using namespace std;
/*
�Ƴ��ض���Ԫ��
*/


int removeElement(int A[], int n, int elem)
{
	int index = 0;

	for (int i = 0; i < n; ++i)
	{
		if (A[i] != elem)
			A[index++] = A[i];
	}

	return index;
}

int main()
{
	return 1;
}