#include <iostream>
#include <sstream>

using namespace std;

//��λ��pos��ʼ���� ��str[pos]��ȵ��ַ� ��������λ�õ���һ��λ�� �����ڷ���-1
int findPos(string str, int pos)
{
	int size = str.size();
	int i = pos + 1;
	for (; i < size; ++i)
	{
		if (str[i] != str[pos])
			break;
	}

	return i;
}

string countAndSay(int n) 
{
	string result = "1";

	for (int i = 2; i <= n; ++i)
	{
		stringstream temp;

		int size = result.size();
		for (int pos = 0; pos < size;)
		{
			int j = findPos(result, pos);

			temp << j - pos << result[pos];

			pos = j;
		}

		temp >> result;
	}

	return result;
}




int main()
{
	string re = countAndSay(20);

	cout << re.c_str() << endl;

	return 1;
}