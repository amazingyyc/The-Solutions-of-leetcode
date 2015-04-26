#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************************************/
/* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.                                                                     */
/************************************************************************/

int maxArea(vector<int> &height) 
{
	int l = 0;
	int r = height.size() - 1;
	int max_area = 0;

	while (l < r)
	{
		max_area = max(max_area, (r - l)*min(height[l], height[r]));

		if (height[l] <= height[r])
			l++;
		else
			r--;
	}

	return max_area;
}

int main()
{
	return 1;
}