#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct UndirectedGraphNode 
{
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

/*UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
{
	if (NULL == node)	return NULL;

	unordered_map<UndirectedGraphNode*, int> read;
	stack<UndirectedGraphNode*> stac;

	stac.push(node);
	read[node]++;
	while (!stac.empty())
	{
		UndirectedGraphNode* top = stac.top();
		stac.pop();

		vector<UndirectedGraphNode *>::iterator it = top->neighbors.begin();
		for (; it != top->neighbors.end(); ++it)
		{
			if (read.find(*it) == read.end())
			{
				stac.push(*it);
				read[*it]++;
			}
				
		}

		UndirectedGraphNode* index = new UndirectedGraphNode(top->label);
		top->neighbors.push_back(index);
	}

	read.clear();
	stac.push(node);
	read[node]++;
	while (!stac.empty())
	{
		UndirectedGraphNode* top = stac.top();
		stac.pop();

		UndirectedGraphNode* index = top->neighbors.back();

		vector<UndirectedGraphNode*>::iterator it = top->neighbors.begin();
		for (; it != top->neighbors.end() - 1; ++it)
		{
			index->neighbors.push_back((*it)->neighbors.back());

			if (read.find(*it) == read.end())
			{
				stac.push(*it);
				read[*it]++;
			}
		}
	}

	UndirectedGraphNode* re = node->neighbors.back();

	read.clear();
	stac.push(node);
	read[node]++;
	while (!stac.empty())
	{
		UndirectedGraphNode* top = stac.top();
		stac.pop();

		top->neighbors.pop_back();

		vector<UndirectedGraphNode*>::iterator it = top->neighbors.begin();
		for (; it != top->neighbors.end(); ++it)
		{
			if (read.find(*it) == read.end())
			{
				stac.push(*it);
				read[*it]++;
			}
		}
	}

	return re;
}*/
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (NULL == node)	return NULL;

	unordered_map<UndirectedGraphNode*, int> read;
	unordered_map<int, UndirectedGraphNode*> map;
	stack<UndirectedGraphNode*> stac;

	stac.push(node);
	read[node]++;
	while(!stac.empty())
	{
		UndirectedGraphNode* top = stac.top();
		stac.pop();

		UndirectedGraphNode* index = NULL;
		if (map.find(top->label) != map.end())
		{
			index = map[top->label];
		}
		else
		{
			index = new UndirectedGraphNode(top->label);
			map[index->label] = index;
		}

		vector<UndirectedGraphNode*>::iterator it = top->neighbors.begin();
		for (; it != top->neighbors.end(); ++it)
		{
			UndirectedGraphNode* n = *it;

			if (map.find(n->label) != map.end())
				index->neighbors.push_back(map[n->label]);
			else
			{
				UndirectedGraphNode* temp = new UndirectedGraphNode(n->label);

				index->neighbors.push_back(temp);
				map[temp->label] = temp;
			}

			if (read.find(n) == read.end())
			{
				stac.push(n);

				read[n]++;
			}
		}
	}

	return map[node->label];
}


int main()
{
	cloneGraph(NULL);

	return 1;
}