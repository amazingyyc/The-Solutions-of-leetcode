#include <iostream>

using namespace std;

//�ַ���ƥ��
//ʹ��kmp�㷨����ƥ��

int KMP(char* text, char* target) 
{
	//�õ�����
	int n = strlen(text);
	int m = strlen(target);

	if (n < m)	return -1;
	if (0 == m) return 0;

	//�洢 ǰ׺ƥ��� ����С
	//next[k]��ʾ ǰk���ַ� ǰ׺��ȵ������� ��0-k-1��ȵ�������
	int *next = (int*)malloc(sizeof(int)*m);
	next[0] = 0;

	for (int i = 1; i < m; ++i)
	{
		int j = next[i - 1];

		while (j >0 && target[j] != target[i])
		{
			j = next[j - 1];
		}

		if (target[j] == target[i])
			next[i] = j + 1;
		else
			next[i] = 0;
	}

	//����ƥ��
	int index = 0;
	for (int i = 0; i < n;)
	{
		if (text[i] == target[index])
		{
			i++;
			index++;

			if (index == m)
				return i - m;
		}
		else if (0 == index)
			i++;
		else
			index = next[index - 1];
	}

	return -1;
}

int main()
{
	int index = KMP("bbaab", "aab");

	return 1;
}