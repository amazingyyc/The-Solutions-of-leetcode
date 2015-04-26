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

 static bool compare(Interval i1, Interval i2)
 {
	 return i1.start < i2.start;
 }

 vector<Interval> merge(vector<Interval> &intervals) 
 {
	 vector<Interval> result;

	 if (intervals.empty())	return result;

	 //ÅÅĞò
	 sort(intervals.begin(), intervals.end(), compare);

	 int index = 0;
	 int right = intervals[index].end;

	 int size = intervals.size();
	 for (int i = 1; i < size; ++i)
	 {
		 if (right < intervals[i].start)
		 {
			 result.push_back(Interval(intervals[index].start, right));

			 index = i;
			 right = intervals[index].end;
		 }
		 else
			 right = max(right, intervals[i].end);
	 }

	 result.push_back(Interval(intervals[index].start, right));

	 return result;
 }

int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1, 3));
	intervals.push_back(Interval(8, 10));
	intervals.push_back(Interval(2, 6));
	intervals.push_back(Interval(15, 18));

	vector<Interval> re = merge(intervals);

	return 1;
}