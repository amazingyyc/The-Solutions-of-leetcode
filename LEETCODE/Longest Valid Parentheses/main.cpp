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

	int last = -1;	//存储断点 既存储上一个 不连续的位置用于计算长度
	int max_num = 0;

	int size = s.size();
	for (int i = 0; i < size; ++i)
	{
		char c = s[i];

		if ('(' == c)
		{
			//如果当前字符是(直接压入栈
			stac.push(i);
		}
		else if (stac.empty())
		{
			//且字符为) 如果当前为空 表明是一个断点
			last = i;
		}
		else
		{
			//这是栈顶是一个( 配对弹出
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