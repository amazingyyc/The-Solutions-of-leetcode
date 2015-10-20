#include <iostream>

using namespace std;

/************************************************************************/
/* Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.                                                                     */
/************************************************************************/

int computeArea(int bottom1, int left1, int top1, int right1, 
	int bottom2, int left2, int top2, int right2)
{
	if (right1 <= left2 || left1 >= right2 || bottom1 >= top2 || top1 <= bottom2)
		return (right1 - left1)*(top1 - bottom1) + (right2 - left2)*(top2 - bottom2);

	int left = (left1 >= left2 && left1 <= right2) ? left1 : left2;
	int right = (right1 >= left2 && right1 <= right2) ? right1 : right2;
	int bottom = (bottom1 >= bottom2 && bottom1 <= top2) ? bottom1 : bottom2;
	int top = (top1 >= bottom2 && top1 <= top2) ? top1 : top2;

	return (right1 - left1)*(top1 - bottom1) + (right2 - left2)*(top2 - bottom2) - (right - left) * (top - bottom);
}

int main()
{
	int sum = computeArea(0, -3, 4, 3, -1, 0, 2, 9);

	return 0;
}