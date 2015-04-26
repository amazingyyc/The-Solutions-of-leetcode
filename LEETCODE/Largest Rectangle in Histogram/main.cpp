#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/************************************************************************/
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

Hide Tags Array Stack

����ջ ��������ڵ�ǰջ��Ԫ�ؾ���ջ�����С�ڵ�ǰ��ջ��Ԫ����ô�Ͷ�ջ���Ԫ�ؽ��д��� ֱ��ջ��Ԫ��С�ڵ�ǰֵ 
�������ջ����һ������ջ  ��һֱ���Խ��д��� �����Ҫ�ֶ����һ��0


*/
/************************************************************************/

int largestRectangleArea(vector<int> &height) 
{
	if (height.empty())	return 0;

	stack<int> stac;
	int result = INT_MIN;

	height.push_back(0);
	int size = height.size();
	for (int i = 0; i < size;)
	{
		if (stac.empty() || height[i] > height[stac.top()])
			stac.push(i++);
		else
		{
			//ɾ��ջ��Ԫ��
			int top = stac.top();
			stac.pop();

			result = max(result, height[top] * (stac.empty() ? i : i- stac.top() - 1));
		}
	}

	return result;
}


int main()
{
	vector<int> height;
	height.push_back(1);

	largestRectangleArea(height);

	return 1;
}