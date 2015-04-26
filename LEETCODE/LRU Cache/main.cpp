#include <iostream>
#include <unordered_map>

using namespace std;

struct PAIR
{
	int key;	//key值
	int rate;	//权值

	bool operator < (PAIR& p)
	{
		return this->rate < p.rate;
	}
};

class LRUCache
{
private:
	int cur_cap;
	int max_cap;	//容量大小

	int cur_rate;	//当前的权值

	PAIR* rates;	//这是一个最小堆

	unordered_map<int, int> contents;	//存储key value
	unordered_map<int, int> indexs;		//存储key 在rate

private:
	//向上修复 并且同时跟新indexs的值
	void fixUp(int i)
	{
		while (1 < i)
		{
			//父亲节点
			int f = i / 2;

			if (rates[f] < rates[i])
				break;

			swap(rates[f], rates[i]);

			indexs[rates[i].key] = i;
			indexs[rates[f].key] = f;

			i = f;
		}
	}

	//向下修复
	void fixDown(int i)
	{
		while (i <= cur_cap / 2)
		{
			int j = 2 * i;

			if ((j + 1) <= cur_cap && rates[j + 1] < rates[j])
				j++;

			if (rates[i] < rates[j])
				break;

			swap(rates[i], rates[j]);

			indexs[rates[i].key] = i;
			indexs[rates[j].key] = j;

			i = j;
		}
	}

	//向堆中插入一条记录
	void insert(int key, int value)
	{
		if (cur_cap < max_cap)
		{
			cur_cap++;

			rates[cur_cap].key = key;
			rates[cur_cap].rate = cur_rate++;

			contents[key] = value;
			indexs[key] = cur_cap;

			return;
		}

		//删除第一条并且跟新
		int del_key = rates[1].key;

		contents.erase(del_key);
		indexs.erase(del_key);

		rates[1].key = key;
		rates[1].rate = cur_rate++;

		contents[key] = value;
		indexs[key] = 1;

		fixDown(1);
	}
public:
	LRUCache(int capacity) 
	{
		cur_cap = 0;
		max_cap = capacity;
		rates = new PAIR[max_cap + 1];

		cur_rate = 1;
	}

	int get(int key) 
	{
		if (contents.find(key) == contents.end())
			return -1;

		//更新权值
		rates[indexs[key]].rate = cur_rate++;

		fixDown(indexs[key]);

		return contents[key];
	}

	void set(int key, int value) 
	{
		//如果当前key已经存在
		if (contents.find(key) != contents.end())
		{
			//更新value
			contents[key] = value;

			//跟新权值
			rates[indexs[key]].rate = cur_rate++;

			fixDown(indexs[key]);

			return;
		}

		//如果不存在就插入
		insert(key, value);
	}
};

int main()
{
	return 1;
}