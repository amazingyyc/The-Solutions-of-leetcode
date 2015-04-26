#include <iostream>

using namespace std;

/*
�洢����ˮ
*/

int trap(int A[], int n)
{
	if (2 >= n)
		return 0;

	/*
	l�洢��ߵ����߶��ڵ�λ�� lHΪ��Ӧ�ĸ߶�
	r�洢�ұ����ĸ߶� rHΪ��Ӧ��ֵ 
	*/
	int l = 0;
	int r = 1;
	int maxH = r;	//�洢�м����������ֵ

	int sum = 0;	//�ܵ�����

	while (r < n)
	{
		if (A[r] < A[l])
		{
			if (A[r] > A[maxH])
				maxH = r;

			r++;
		}
		else if ( (l+1) != r )
		{
			for (int k = l + 1; k < r; ++k)
			{
				sum += A[l] - A[k];
			}

			l = r;
			r++;

			maxH = r;
		}
		else
		{
			l++;
			r++;

			maxH = r;
		}
	}

	//��ʱl �洢һ������ߵ���ֵ ��maxH�洢��l��ʼ������������ֵ
	while (l < n - 1)
	{
		for (int k = l + 1; k < maxH; ++k)
			sum += A[maxH] - A[k];

		l = maxH;

		maxH = l + 1;
		for (int i = l + 1; i < n; ++i)
		{
			if (A[i] > A[maxH])
				maxH = i;
 		}
	}

	return sum;
}

int main()
{
	int A[12] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

	int sum = trap(A, 12);

	return 1;
}