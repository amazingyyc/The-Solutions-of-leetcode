#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode 
{
public:
	char data;	//对应的字符
	vector<TrieNode*> child;	//孩子节点

public:
	// Initialize your data structure here.
	TrieNode() 
	{
	}

	TrieNode(char c)
	{
		data = c;
	}
};

class Trie 
{
public:
	Trie() 
	{
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) 
	{
		TrieNode* cur = root;
		int size = word.size();
		for (int i = 0; i < size; ++i)
		{
			TrieNode* node = findCharFromChild(cur, word[i]);

			if (NULL == node)
			{
				node = new TrieNode(word[i]);
				cur->child.push_back(node);
			}

			cur = node;
		}

		cur->child.push_back(NULL);
	}

	// Returns if the word is in the trie.
	bool search(string word) 
	{
		TrieNode* cur = root;
		int size = word.size();

		for (int i = 0; i < size; ++i)
		{
			TrieNode* node = findCharFromChild(cur, word[i]);

			if (NULL == node)
				return false;

			cur = node;
		}

		return containsNULL(cur->child);
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) 
	{
		TrieNode* cur = root;
		int size = prefix.size();

		for (int i = 0; i < size; ++i)
		{
			TrieNode* node = findCharFromChild(cur, prefix[i]);

			if (NULL == node)
				return false;

			cur = node;
		}

		return true;
	}

private:
	TrieNode* findCharFromChild(TrieNode* nodes, char data)
	{
		for (TrieNode* t : nodes->child)
		{
			if (NULL != t && t->data == data)
				return t;
		}

		return NULL;
	}

	bool containsNULL(vector<TrieNode*> nodes)
	{
		vector<TrieNode*>::iterator it = nodes.begin();
		for (; it != nodes.end(); ++it)
		{
			if (NULL == *it)
				return true;
		}

		return false;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	Trie t;

	t.insert("abc");
	t.search("abc");
	t.search("ab");
	t.insert("ab");
	t.search("ab");
	t.insert("ab");
	t.search("ab");

	return 0;
}