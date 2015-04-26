#include <iostream>

using namespace std;

/*
��n�Ľײ����ҳ���k�� ����
*/

int getNumber(int number[], int n, int k)
{
	//������number���ҵ�kС���� ��0��ʼ����
	int count = -1;

	for (int i = 0; i <= n; ++i)
	{
		if (0 == number[i])
		{
			count++;

			if (count == k)
				return i;
		}
	}

	return -1;
}

string getPermutation(int n, int k)
{
	int sum = 1;

	for (int i = 1; i <= n; ++i)
		sum *= i;

	if (0 >= k || k > sum)
		return "";

	//��k��һ ��0��ʼ ����
	k--;

	int number[10] = {0};	//���������洢��ǰ�����Ƿ�ʹ�� �������5�Ѿ���ʹ����number[5] = 1 ����Ϊ0
	string str[10] = {"0","1","2","3","4","5","6","7","8", "9"};
	number[0] = 1;
	int d = n;
	string re = "";

	while (d > 0)
	{
		sum /= d;

		int s = k / sum;
		k = k % sum;

		int c = getNumber(number, n, s);

		if (-1 != c)
		{
			number[c] = 1;

			re += str[c];
		}
		else
			return "";

		d--;
	}

	return re;
}

int main()
{
	string re = getPermutation(5, 10);

	return 1;
}