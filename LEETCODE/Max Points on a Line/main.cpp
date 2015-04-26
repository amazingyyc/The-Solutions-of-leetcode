#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	
};

int maxPoints(vector<Point> &points) 
{
	int n = points.size();

	if (2 >= n)	return n;

	unordered_map<double, int> lines;
	int samePoints = 1;	//与开始点相同的节点个数
	int parallelPoints = 0;	//与开始点 和y轴平行
	int maxPoints = 0;

	for (int i = 0; i < n; ++i)
	{
		int x1 = points[i].x;
		int y1 = points[i].y;

		int sum = 0;
		samePoints = 1;
		parallelPoints = 0;
		lines.clear();

		for (int j = i + 1; j < n; ++j)
		{
			int x2 = points[j].x;
			int y2 = points[j].y;

			if (x1 == x2 && y1 == y2)
			{
				samePoints++;
				continue;
			}

			if (x1 == x2)
			{
				parallelPoints++;
				sum = max(parallelPoints, sum);
				continue;
			}

			double k = (1.0*y2 - 1.0*y1) / (1.0*x2 - 1.0*x1);
			lines[k]++;

			sum = max(lines[k], sum);
		}

		maxPoints = max(sum + samePoints, maxPoints);
	}

	return maxPoints;
	
}


int main()
{
	vector<Point> points;
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 1));
	points.push_back(Point(0, 0));

	maxPoints(points);

	return 1;
}