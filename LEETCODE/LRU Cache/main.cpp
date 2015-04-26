#include <iostream>
#include <unordered_map>

using namespace std;

struct PAIR
{
	int key;	//keyֵ
	int rate;	//Ȩֵ

	bool operator < (PAIR& p)
	{
		return this->rate < p.rate;
	}
};

class LRUCache
{
private:
	int cur_cap;
	int max_cap;	//������С

	int cur_rate;	//��ǰ��Ȩֵ

	PAIR* rates;	//����һ����С��

	unordered_map<int, int> contents;	//�洢key value
	unordered_map<int, int> indexs;		//�洢key ��rate

private:
	//�����޸� ����ͬʱ����indexs��ֵ
	void fixUp(int i)
	{
		while (1 < i)
		{
			//���׽ڵ�
			int f = i / 2;

			if (rates[f] < rates[i])
				break;

			swap(rates[f], rates[i]);

			indexs[rates[i].key] = i;
			indexs[rates[f].key] = f;

			i = f;
		}
	}

	//�����޸�
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

	//����в���һ����¼
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

		//ɾ����һ�����Ҹ���
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

		//����Ȩֵ
		rates[indexs[key]].rate = cur_rate++;

		fixDown(indexs[key]);

		return contents[key];
	}

	void set(int key, int value) 
	{
		//�����ǰkey�Ѿ�����
		if (contents.find(key) != contents.end())
		{
			//����value
			contents[key] = value;

			//����Ȩֵ
			rates[indexs[key]].rate = cur_rate++;

			fixDown(indexs[key]);

			return;
		}

		//��������ھͲ���
		insert(key, value);
	}
};

int main()
{
	return 1;
}