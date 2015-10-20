#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode
{
	bool isLeaf = false;	//是否是叶子节点
	unordered_map<char, TrieNode*> childs;	//儿子节点

	TrieNode(bool l)
	{
		isLeaf = l;
	}
};

class WordDictionary 
{
private:
	TrieNode* root;
public:
	WordDictionary()
	{
		root = new TrieNode(false);
	}

	// Adds a word into the data structure.
	void addWord(string word) 
	{
		TrieNode* cur = root;
		int size = word.size();
		for (int i = 0; i < size; ++i)
		{
			//未查找到
			if (cur->childs.find(word[i]) == cur->childs.end())
			{
				cur->childs[word[i]] = new TrieNode(false);
			}

			cur = cur->childs[word[i]];
		}

		cur->isLeaf = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) 
	{
		return search(word, word.size(), 0, root);
	}
private:
	bool search(string word, int size, int index, TrieNode* cur)
	{
		if (index >= size)
			return cur->isLeaf;

		if ('.' == word[index])
		{
			unordered_map<char, TrieNode*>::iterator it = cur->childs.begin();
			for (; it != cur->childs.end(); ++it)
			{
				if (search(word, size, index + 1, (*it).second))
					return true;
			}

			return false;
		}
		else if(cur->childs.find(word[index]) != cur->childs.end())
		{
			return search(word, size, index + 1, cur->childs[word[index]]);
		}
		else
		{
			return false;
		}
	}
};

int main()
{


	return 0;
}