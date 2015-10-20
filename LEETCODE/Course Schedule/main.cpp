#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/************************************************************************/
/* There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.                                                                     */
/************************************************************************/

//存储一个节点
struct Node
{
	vector<int> next;
};

//对图进行拓扑排序
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
{
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
		count--;

		vector<int>::iterator it = nodes[top].next.begin();
		for (; it != nodes[top].next.end(); ++it)
		{
			indegree[*it]--;

			if (0 == indegree[*it])
				que.push(*it);
		}
	}

	return 0 == count;
}

int main()
{
	int a = 0;

	return 0;
}