#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1                                                                     
*/
/************************************************************************/

/*
�Ӻ���ǰ ���� ����4����� 
1��һ�µݼ��� ֻ��Ҫ��ת�������Ԫ�ؼ���
2���ݼ�����ĳ���ط�ֹͣ ��ת�������Ԫ��
3:��֪���� ��ת��������
4��������ĳ���ط�ֹͣ ����num[i] < num[i+1] ֻ��Ҫ��num��i����֮��Ĵ���num��i����С��Ԫ�ؽ��� Ȼ��ת ���������� ����
*/
void nextPermutation(vector<int> &num) 
{
	int size = num.size();

	if (0 == size || 1 == size)	return;

	//ȥ����ȵ�Ԫ��
	int i = size - 1;
	while (i >= 1 && num[i] == num[i - 1])	--i;

	//�������ж����
	if (0 == i)	return;

	//int r = i;

	if (num[i] > num[i - 1])
	{
		//���ڴ������ҵĵݼ����� ֻ��Ҫ��ת�������Ԫ��
		swap(num[i], num[i - 1]);
		return;
	}
		
	for (; i >= 1; --i)
	{
		if (num[i - 1] < num[i])
			break;
	}

	int l = i;
	int r = size - 1;

	if (0 != i)
	{
		int j;
		for (j = i; j < r; ++j)
		{
			if (num[j] >= num[i - 1] && num[j + 1] <= num[i - 1])
				break;
		}

		swap(num[i - 1], num[j]);
	}

	while (l < r)
	{
		swap(num[l++], num[r--]);
	}
}

int main()
{
	vector<int> num;
	num.push_back(5);
	num.push_back(1);
	num.push_back(1);

	nextPermutation(num);

	return 1;
}