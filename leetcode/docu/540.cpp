#include "cpp_header.h"

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		int m;
		int res = INT_MAX;

		while( (left+1) < right )
		{
			m = (left+right)/2;
			if(m % 2 == 1)
			{
				if(nums[m-1] == nums[m])
				{
					left = m;
				}
				else
				{
					res = nums[m-1];
					right = m;
				}
			}
			else if(m % 2 == 0 && m > 0)
			{
				if(nums[m] == nums[m+1])
				{
					left = m;
				}
				else
				{
					res = nums[m];
					right = m;
				}
			}
		}

		if(res == INT_MAX)
		{
			res = nums.back();
		}

		return res;
	}
};

int testcase(vector<int>& nums, int res, int casenum)
{
	Solution sol;
	if(sol.singleNonDuplicate(nums) == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
	}

	return 0;
}

int main()
{
	vector<int> nums;
	int res;
	int casenum;

	nums = {1,2,2,3,3};
	res = 1;
	casenum = 1;

	testcase(nums, res, casenum);

	nums = {1,1,2,3,3};
	res = 2;
	casenum = 2;

	testcase(nums, res, casenum);

	nums = {1,1,2,2,3};
	res = 3;
	casenum = 3;

	testcase(nums, res, casenum);

	nums = {1,1,2,2,3,4,4};
	res = 3;
	casenum = 4;

	testcase(nums, res, casenum);

	nums = {1};
	res = 1;
	casenum = 5;

	testcase(nums, res, casenum);

	nums = {0,1,1};
	res = 0;
	casenum = 6;

	testcase(nums, res, casenum);

}





