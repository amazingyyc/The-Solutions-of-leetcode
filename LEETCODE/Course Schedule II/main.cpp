#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//存储一个节点
struct Node
{
	vector<int> next;
};

//对图进行拓扑排序
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<int> result;
	vector<int> indegree(numCourses, 0);	//存储入度
	queue<int> que;	//入度为0的队列

	vector<Node> nodes(numCourses);

	vector<pair<int, int>>::iterator it;
	for (it = prerequisites.begin(); it != prerequisites.end(); ++it)
	{
		nodes[it->second].next.push_back(it->first);
		indegree[it->first]++;
	}

	for (int i = 0; i < numCourses; ++i)
	{
		if (0 == indegree[i])
			que.push(i);
	}

	int count = numCourses;

	while (!que.empty())
	{
		int top = que.front();
		que.pop();
		result.push_back(top);
		count--;

		vector<int>::iterator it = nodes[top].next.begin();
		for (; it != nodes[top].next.end(); ++it)
		{
			indegree[*it]--;

			if (0 == indegree[*it])
				que.push(*it);
		}
	}

	return 0 == count?result:vector<int>();
}

int main()
{
	return 0;
}