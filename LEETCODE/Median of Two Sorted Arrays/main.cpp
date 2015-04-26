#include <iostream>
#include <algorithm>

using namespace std;

/*
�����м�ֵ 
���m+nΪ���� �����м��һ��ֵ Ϊż�������м������ֵ��ƽ����
*/

//���ص�k���� ��1��ʼ 
int findTheKNumber(int A[], int m, int B[], int n, int k)
{
	//k<=m+n ����
	int a = 0;
	int b = 0;

	while (1)
	{
		if (a >= m)
			return B[b + k - 1];
		else if (b >= n)
			return A[a + k - 1];

		if (1 == k)
			return min(A[a], B[b]);

		int incre = min(k / 2, min(m - a, n - b));

		if (A[a + incre - 1] >= B[b + incre - 1])
			b = b + incre;
		else
			a = a + incre;

		k = k - incre;
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	if (0 == m && 0 == n)
		return 0;

	bool ev = (m + n) & 0x1;	//�Ƿ�Ϊ ������ż�� true���� falseż��
	int k = (m + n) / 2;

	if (ev)
		return findTheKNumber(A, m, B, n, k + 1);
	else
		return (findTheKNumber(A, m, B, n, k) + findTheKNumber(A, m, B, n, k + 1))/2.0;
}

int main()
{
	int A[4] = { 1, 3, 8, 20 };
	int B[3] = { 2, 4, 19 };

	double mid = findMedianSortedArrays(A, 4, B, 3);

	return 1;
}