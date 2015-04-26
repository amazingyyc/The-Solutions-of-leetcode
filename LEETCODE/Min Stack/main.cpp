#include <iostream>

using namespace std;

class MinStack 
{
private:
	int* arr;
	int len;
	int end;
	int index;
public:
	MinStack()
	{
		len = 10;
		arr = new int[len];

		end = 0;
		index = -1;
	}

	~MinStack()
	{
		delete[] arr;
	}

	void push(int x) 
	{
		if (end >= len)
		{
			len *= 2;
			int* temp = new int[len];
			for (int i = 0; i < end; ++i)
				temp[i] = arr[i];

			delete[] arr;

			arr = temp;
		}

		arr[end++] = x;

		if (-1 == index || x < arr[index])
			index = end - 1;
	}

	void pop() 
	{
		if (0 == end)
			return;

		end--;

		if (index == end)
		{
			index = end - 1;

			for (int i = end - 2; i >= 0; --i)
			if (arr[i] < arr[index])
				index = i;
		}
	}

	int top() 
	{
		if (0 == end)
			return -1;

		return arr[end - 1];
	}

	int getMin() 
	{
		if (-1 == index)
			return -1;

		return arr[index];
	}
};

int main()
{
	MinStack stac;

	stac.push(395);
	stac.getMin(); 
	stac.top();
	stac.getMin();
	stac.push(276); 
	stac.push(29); 
	stac.getMin();
	stac.push(-482); 
	stac.getMin();
	stac.pop();
	stac.push(-108); 
	stac.push(-251); 
	stac.getMin();
	stac.push(-439); 
	stac.top();
	stac.push(370);
	stac.pop();
	stac.pop();
	stac.getMin();
	stac.pop();
	stac.getMin();
	stac.getMin();
	stac.pop();
	stac.getMin();

	return 1;
}