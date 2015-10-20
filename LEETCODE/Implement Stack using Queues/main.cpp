#include <iostream>
#include <queue>

using namespace std;

class Stack 
{
private:
	queue<int> que;	//����
	bool first;	//true��ʾ���һ��Ԫ���Ѿ��ƶ�����ǰ�� false��ʾ ����ԭʼ�����м�������

private:
	void move_que()
	{
		if (first)	return;

		int size = que.size() - 1;
		while (size--)
		{
			que.push(que.front());
			que.pop();
		}

		first = true;
	}
public:
	Stack()
	{
		first = false;
	}

	// Push element x onto stack.
	void push(int x) 
	{
		if (first)
		{
			que.push(que.front());
			que.pop();
			
			first = false;
		}
		que.push(x);
	}

	// Removes the element on top of the stack.
	void pop() 
	{
		if (!first)
		{
			move_que();
		}

		que.pop();

		first = false;
	}

	// Get the top element.
	int top() 
	{
		if (!first)
		{
			move_que();
		}

		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() 
	{
		return que.empty();
	}
};

int main()
{
	return 0;
}