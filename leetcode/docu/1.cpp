#include "cpp_header.h"

class Solution {
public:
	vector<int> twoSum(vector<int>&nums, int target)
	{
		vector<int> res(2, -1);
		int first = 0, second = 0;

		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				if(target - nums[i] == nums[j])
				{
					res[0] = i;
					res[1] = j;
					break;
				}
			}
			if(res[0] != -1)
				break;
		}

		return res;
	}

};

int main()
{
	vector<int> nums;
	int target;
	vector<int> res;
	int casenum;

	nums = {2,7,11,15};
	target = 9;
	res = {0,1};
	casenum = 1;
	TESTCASE_p2(twoSum, nums, target, res, casenum);
	
	nums = {2,3,6,11,15};
	target = 8;
	res = {0,2};
	casenum = 2;
	TESTCASE_p2(twoSum, nums, target, res, casenum);
	
	nums = {2,3,4,4,6,11,15};
	target = 8;
	res = {0,4};
	casenum = 3;
	TESTCASE_p2(twoSum, nums, target, res, casenum);
	
	nums = {3,2,4};
	target = 6;
	res = {1,2};
	casenum = 4;
	TESTCASE_p2(twoSum, nums, target, res, casenum);
	
	nums = {3,3,4};
	target = 6;
	res = {0,1};
	casenum = 5;
	TESTCASE_p2(twoSum, nums, target, res, casenum);
	
}
