#include "cpp_header.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		int len = 1;
		if(nums.size() == 0) return 0;

		for(int i = 0; i < nums.size() - 1; )
		{
			int j = i + 1;
			for( ; j < nums.size(); j++)
			{
				if(nums[i] == nums[j])
					continue;
				nums[len++] = nums[j];
				break;
			}
			i = j;
		}
		cout << len << "\n";

		return len;
	}
};

int main()
{
	vector<int> nums;
	int res;
	int casenum;

	nums = {1,1,2};
	res = 2;
	casenum = 1;
	TESTCASE_p1(removeDuplicates, nums, res, casenum);

	nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	res = 5;
	casenum = 2;
	TESTCASE_p1(removeDuplicates, nums, res, casenum);

	nums = {1};
	res = 1;
	casenum = 3;
	TESTCASE_p1(removeDuplicates, nums, res, casenum);

	nums = {};
	res = 0;
	casenum = 4;
	TESTCASE_p1(removeDuplicates, nums, res, casenum);

	nums = {1,1};
	res = 1;
	casenum = 5;
	TESTCASE_p1(removeDuplicates, nums, res, casenum);

	nums = {1,1,1,1,1,1};
	res = 1;
	casenum = 6;
	TESTCASE_p1(removeDuplicates, nums, res, casenum);



}

