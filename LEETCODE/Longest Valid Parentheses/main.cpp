#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
int longestValidParentheses(string s) 
{
	stack<int> stac;

	int last = -1;	//�洢�ϵ� �ȴ洢��һ�� ��������λ�����ڼ��㳤��
	int max_num = 0;

	int size = s.size();
	for (int i = 0; i < size; ++i)
	{
		char c = s[i];

		if ('(' == c)
		{
			//�����ǰ�ַ���(ֱ��ѹ��ջ
			stac.push(i);
		}
		else if (stac.empty())
		{
			//���ַ�Ϊ) �����ǰΪ�� ������һ���ϵ�
			last = i;
		}
		else
		{
			//����ջ����һ��( ��Ե���
			stac.pop();

			if (stac.empty())
				max_num = max(max_num, i - last);
			else
				max_num = max(max_num, i - stac.top());
		}
	}

	return max_num;
}

int main()
{

	return 1;
}