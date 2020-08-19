#include "cpp_header.h"

class Solution {

	struct {
		bool operator()(const int& a, const int& b)
		{
			return a < b;
		}
	}lessEqual;

	int less_equal(vector<int>& nums, int c)
	{
		int l = 0, r = nums.size() - 1;
		int m;

		while(l <= r)
		{
			m = (l+r)/2;
			if(nums[m] <= c)
			{
				l = m+1;
			}
			else if(nums[m] > c)
			{
				r = m-1;
			}
		}
		if(r < 0)
			return -1;
		if(l > nums.size())
			return nums.back();
		return nums[r];
	}

public:
	int findRadius(vector<int>& houses, vector<int>& heaters)
	{
//		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		int distance = 0;

		for(int i = 0; i < houses.size(); i++)
		{
			int d = 0;

			auto lit = less_equal(heaters, houses[i]);
			auto rit = lower_bound(heaters.begin(), heaters.end(), houses[i]);
			cout << houses[i] << "  ";
			if(lit == -1 && rit != heaters.end())
			{
				d = abs((*rit) - houses[i]);
				cout << "N  " << (*rit) << "  " << "\n";
			}
			else if(lit != -1 && rit == heaters.end())
			{
				d = abs((lit) - houses[i]);
				cout << (lit) << "  N   " << "\n";
			}
			else if(lit != -1 && rit != heaters.end())
			{
				d = min(abs((lit) - houses[i]), abs((*rit) - houses[i]));
				cout << (lit) << "  " << (*rit) << "  " << "\n";
			}
			else
				cout << "N   N" << "\n";
			if(distance < d)
				distance = d;
		}

		return distance;
	}
};

int main()
{
	vector<int> houses;
	vector<int> heaters;
	int res;
	int casenum;

	houses = {1,2,3};
	heaters = {2};
	res = 1;
	casenum = 1;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4};
	heaters = {1,4};
	res = 1;
	casenum = 2;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);


	houses = {1,2,3,4};
	heaters = {1,3};
	res = 1;
	casenum = 3;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4};
	heaters = {1,2};
	res = 2;
	casenum = 4;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {1,2};
	res = 3;
	casenum = 5;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {1,3};
	res = 2;
	casenum = 6;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {1,4};
	res = 1;
	casenum = 7;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {1,5};
	res = 2;
	casenum = 8;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {1};
	res = 4;
	casenum = 9;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {2};
	res = 3;
	casenum = 10;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {3};
	res = 2;
	casenum = 11;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {4};
	res = 3;
	casenum = 12;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1,2,3,4,5};
	heaters = {5};
	res = 4;
	casenum = 13;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {1};
	heaters = {1,2,3,4};
	res = 0;
	casenum = 14;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {2};
	heaters = {1,5};
	res = 1;
	casenum = 15;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);

	houses = {3,7};
	heaters = {1,10};
	res = 3;
	casenum = 16;
	TESTCASE_p2(findRadius, houses, heaters, res, casenum);
}
