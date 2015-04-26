#include <iostream>

using namespace std;

//�ϲ�a �� b a���㹻�Ŀռ� �洢
void merge(int A[], int m, int B[], int n)
{
	//������� 
	int k = m + n - 1;
	m--;
	n--;

	while (0 <= m && 0 <= n)
	{
		A[k--] = A[m] > B[n] ? A[m--] : B[n--];
	}

	while (0 <= n)
	{
		A[k--] = B[n--];
	}
}

int main()
{
	int A[100] = { 1, 3, 5, 7 };
	int B[100] = { 2, 4, 6, 8 };

	merge(A, 4, B, 4);

	return 1;
}