#include <iostream>

using namespace std;

/*
�������������ظ�
*/
int removeDuplicates(int A[], int n)
{
	if (0 == n)
		return n;

	int index = 0;
	bool count = false;	//�Ƿ��Ѿ��ظ�

	for (int i = 1; i < n; ++i)
	{
		if (A[index] == A[i])
		{
			//������
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