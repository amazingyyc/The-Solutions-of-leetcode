#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TrieNode
{
	bool isLeaf;	//是否是叶子节点

	unordered_map<char, TrieNode*> data;

	TrieNode()
	{
		isLeaf = false;
	}
};

void insertWord(TrieNode* root, string word)
{
	TrieNode* cur = root;
	int size = word.size();
	for (int i = 0; i < size; ++i)
	{
		if (cur->data.find(word[i]) == cur->data.end())
		{
			cur->data[word[i]] = new TrieNode();
		}

		cur = cur->data[word[i]];
	}

	cur->isLeaf = true;
}

void insertWord(TrieNode* root, vector<string> words)
{
	for (string word : words)
	{
		insertWord(root, word);
	}
}

void findStrs(vector<vector<char>>& board, int n, int m, int i, int j,
	vector<vector<bool>>& visited, string pre, TrieNode* cur, vector<string>& result, int max_size)
{
	if (NULL == cur)
		return;

	if (cur->isLeaf)
	{
		result.push_back(pre);
		cur->isLeaf = false;
	}

	if (result.size() >= max_size)
		return;

	if (0 > i || i >= n || 0 > j || j >= m)
		return;

	if (visited[i][j])
		return;

	char c = board[i][j];

	if (cur->data.find(c) != cur->data.end())
	{
		visited[i][j] = true;

		findStrs(board, n, m, i, j - 1, visited, pre + c, cur->data[c], result, max_size);
		findStrs(board, n, m, i, j + 1, visited, pre + c, cur->data[c], result, max_size);
		findStrs(board, n, m, i - 1, j, visited, pre + c, cur->data[c], result, max_size);
		findStrs(board, n, m, i + 1, j, visited, pre + c, cur->data[c], result, max_size);

		visited[i][j] = false;
	}
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
	TrieNode* root = new TrieNode();

	insertWord(root, words);

	//unordered_set<string> set;
	vector<string> result;
	int max_size = words.size();
	int n = board.size();
	int m = board[0].size();

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			findStrs(board, n, m, i, j, visited, "", root, result, max_size);
		}
	}

	return result;
}

int main()
{


	return 0;
}