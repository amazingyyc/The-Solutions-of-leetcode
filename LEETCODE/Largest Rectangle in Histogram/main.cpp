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

利用栈 ：如果大于当前栈顶元素就入栈，如果小于当前在栈顶元素那么就对栈里的元素进行处理 直到栈顶元素小于当前值 
这样这个栈就是一个递增栈  就一直可以进行处理 最后需要手动添加一个0


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
			//删除栈顶元素
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