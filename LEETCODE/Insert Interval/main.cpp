#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct Interval 
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
	int start = newInterval.start;
	int end	  = newInterval.end;

	int size = intervals.size();

	int l = 0;
	int r = size - 1;
	
	for (int i = 0; i < size; ++i)
	{
		if (start < intervals[i].start)
			break;
		else if (start >= intervals[i].start && start <= intervals[i].end)
		{
			l = i;

			break;
		}
		else
			l = i + 1;
	}

	for (int i = size - 1; i >= 0; --i)
	{
		if (end > intervals[i].end)
			break;
		else if (end >= intervals[i].start && end <= intervals[i].end)
		{
			r = i;

			break;
		}
		else
			r = i - 1;
	}

	if (l == size)
	{
		intervals.push_back(newInterval);

		return intervals;
	}

	if (-1 == r)
	{
		intervals.insert(intervals.begin(), newInterval);

		return intervals;
	}
		
	start = min(start, intervals[l].start);
	end   = max(end, intervals[r].end);

	newInterval.start = start;
	newInterval.end = end;

	vector<Interval>::iterator it = intervals.erase(intervals.begin() + l, intervals.begin() + r + 1);

	intervals.insert(it, newInterval);

	return intervals;
}

int main()
{
	return 1;
}