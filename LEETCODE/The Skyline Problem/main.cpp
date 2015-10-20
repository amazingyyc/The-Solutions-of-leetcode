#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool coverLeftPoint(vector<vector<int>>& buildings, int index)
{
	//index对应的左边的边界点 是否被覆盖
	int size = buildings.size();
	for (int i = 0; i < size && buildings[i][0] <= buildings[index][0]; ++i)
	{
		if(i == index || buildings[i][2] < buildings[index][2])
			continue;

		if (buildings[i][0] < buildings[index][0] && buildings[i][1] >= buildings[index][0])
			return true;

		if (buildings[i][0] == buildings[index][0])
		{
			if (buildings[i][2] > buildings[index][2])
				return true;

			if (i < index)
				return true;
		}
	}

	return false;
}

int coverRightPoint(vector<vector<int>>& buildings, int index)
{
	int height = 0;
	int size = buildings.size();
	for (int i = 0; i < size; ++i)
	{
		if(i == index || buildings[i][0] > buildings[index][1] || buildings[i][1] < buildings[index][1])
			continue;
		
		if (buildings[i][2] > buildings[index][2])
			return -1;

		if (buildings[i][1] > buildings[index][1])
		{
			if (buildings[i][2] == buildings[index][2])
				return -1;

			height = max(buildings[i][2], height);
		}

		if (buildings[i][1] == buildings[index][1])
		{
			if (buildings[i][2] == buildings[index][2])
			{
				if (index > i)
					return -1;
			}
		}
	}

	return height;
}

static bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first;
}
 
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
{
	vector<pair<int, int>> res;

	int size = buildings.size();
	int height;
	for (int i = 0; i < size; ++i)
	{
		if (!coverLeftPoint(buildings, i))
		{
			res.push_back(pair<int, int>(buildings[i][0], buildings[i][2]));
		}

		if (-1 != (height = coverRightPoint(buildings, i)))
		{
			res.push_back(pair<int, int>(buildings[i][1], height));
		}
	}

	sort(res.begin(), res.end(), cmp);

	return res;
}

int main()
{


	return 0;
}