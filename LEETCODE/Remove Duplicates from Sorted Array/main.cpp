#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{
	/*
	����ָ�� 
	frֻ�뵱ǰ�ظ������ĵ�һ��λ�� 
	seֻ�뵱ǰ�ظ�����һ��λ��
	thָ��ӿ�ʼ�����в��ظ������һ�� λ�� ���se thֻ����һ����ʾ �����ظ����� ֻ��һ�����ظ�
	*/
	/*if (0 == n)
		return 0;

	int fr = 0;
	int se = 1;
	int th = 1;

	while (se < n)
	{
		while ((se + 1) < n && A[se + 1] == A[se])
		{
			se++;
		}

		th = se;

		while ((th + 1) < n && A[th + 1] != A[th])
		{
			th++;
		}

		if ((fr + 1) != se)
		{
			for (int k = se; k <= th; ++k)
				A[++fr] = A[k];
		}

		se++;
	}

	return fr + 1;*/

	if (0 == n)
		return 0;

	int index = 0;

	for (int i = 1; i < n; ++i)
	{
		if (A[index] != A[i])
		{
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


	return 1;
}