#include "cpp_header.h"

class Solution {
public:
	/* 
	 * boundary condition
	 * 1, overflow, underflow
	 * 2, negative number.
	 *
	 */
	int minMoves(vector<int>& nums)
	{
		long long min_num = INT_MAX;
		long long num_sum = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			num_sum += nums[i];
			if(min_num > nums[i])
				min_num = nums[i];
		}
		cout << num_sum - min_num * nums.size() << "\n";
		return num_sum - min_num * nums.size();
	}
};

int main()
{
	vector<int> nums;
	int res;
	int casenum;

	nums = {1,2,3};
	res = 3;
	casenum = 1;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {1,2,5};
	res = 5;
	casenum = 2;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {1,2,3,4};
	res = 6;
	casenum = 3;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {2,2,3};
	res = 1;
	casenum = 4;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {2,2,2,3};
	res = 1;
	casenum = 5;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {2,2,2,5};
	res = 3;
	casenum = 6;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {1};
	res = 0;
	casenum = 7;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {1,1};
	res = 0;
	casenum = 8;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {1,1,1};
	res = 0;
	casenum = 9;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {1,2147473647};
	res = 2147473646;
	casenum = 10;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {1,1,2147473647};
	res = 2147473646;
	casenum = 11;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {1,2,2147473647};
	res = 2147473647;
	casenum = 12;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {-100,0,100};
	res = 300;
	casenum = 13;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {-2147473641,0,2147473646};
	res = 2147473647;
	casenum = 14;
	TESTCASE_p1(minMoves, nums, res, casenum);

	nums = {-1,0,1};
	res = 3;
	casenum = 15;
	TESTCASE_p1(minMoves, nums, res, casenum);


}
