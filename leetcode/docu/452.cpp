#include "cpp_header.h"

// wrong answer
//
//
//
class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points)
	{

		return answer1(points);
	}

	int answer1(vector<vector<int>>& points)
	{
		for(int i = 0; i < points.size(); i++)
		{
			for(int j = i + 1; j < points.size(); j++)
			{
//				if(is_overlap(points[i], points[j]))
				if(!(points[i][1] < points[j][0] || points[i][0] > points[j][1]))
				{
					points[i][0] = min(points[i][0], points[j][0]);
					points[i][1] = max(points[i][1], points[j][1]);
					points.erase(points.begin() + j);
					j--;
				}
			}
		}

		return points.size();
	}

	bool is_overlap(const vector<int>& p1, const vector<int>& p2)
	{
		if(p1[1] < p2[0] || p1[0] > p2[1])
		{
			return false;
		}
		return true;
	}
};

void testcase(vector<vector<int>> points, int res, int casenum)
{
	Solution sol;

	if(sol.findMinArrowShots(points) == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
	}
}

int main()
{
	vector<vector<int>> points;
	int res;
	int casenum;

	points = {{10,16}, {2,8}, {1,6}, {7,12}};
	res = 2;
	casenum = 1;

	testcase(points, res, casenum);


	points = {{1,2}, {3,4}, {5,6}, {7,12}};
	res = 4;
	casenum = 2;

	testcase(points, res, casenum);

	points = {{1,4}, {3,4}, {5,6}, {7,12}};
	res = 3;
	casenum = 3;

	testcase(points, res, casenum);

	points = {{5,6}};
	res = 1;
	casenum = 4;

	testcase(points, res, casenum);

	points = {};
	res = 0;
	casenum = 5;

	testcase(points, res, casenum);

	points = {{1,2}, {2,3}, {3,4}, {5,6}};
	res = 3;
	casenum = 6;

	testcase(points, res, casenum);

	points = {{1,2}, {2,3}, {3,4}, {4,6}};
	res = 4;
	casenum = 7;

	testcase(points, res, casenum);



}


