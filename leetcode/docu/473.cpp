#include "cpp_header.h"

class Solution {
public:
	bool makesquare(vector<int>& nums)
	{
		int num_sum = 0;
		map<int, int> counts;
		for(auto x : nums)
		{
			num_sum += x;
			counts[x]++;
		}

		if(num_sum % 4 != 0)
			return false;

		int line_len = num_sum / 4;

		sort(nums.begin(), nums.end(), greater<int>());

		int len_count = 0;
		vector<bool> mark(nums.size(), 0);

		for(int i = 0; i < nums.size(); i++)
		{
			if(mark[i] == 1)
				continue;

			if(len_count > 4)
				return false;

			mark[i] = 1;

			if(nums[i] > line_len)
				return false;

			if(nums[i] == line_len)
			{
				len_count++;
				continue;
			}

			if(findLine(nums, i+1, nums[i], line_len, mark) == false)
			{
				return false;
			}

			len_count++;
		}

		if(len_count != 4)
			return false;

		for(auto x : mark)
			if(x == 0)
				return false;

		return true;
	}

	bool findLine(vector<int>& nums, int j, int num, int line_len, vector<bool>& mark)
	{
		while(j < nums.size())
		{
			if(mark[j] == 1)
			{
				j++;
				continue;
			}

			if(nums[j] + num == line_len)
			{
				mark[j] = 1;
				return true;
			}
			else if(nums[j] + num < line_len)
			{
				mark[j] = 1;
				if( findLine(nums, j + 1, num + nums[j], line_len, mark) == false)
				{
					mark[j] = 0;
					j++;
					continue;
				}
				else
					return true;
			}
			else if(nums[j] + num > line_len)
			{
				j++;
			}
		}

		return false;
	}

};


int main()
{
	vector<int> nums;
	int res;
	int casenum;

	nums = {1,1,2,2,2};
	res = true;
	casenum = 1;
	TESTCASE_p1(makesquare, nums, res, casenum);


	nums = {1,1,1,1,1,1,1,1};
	res = true;
	casenum = 2;
	TESTCASE_p1(makesquare, nums, res, casenum);


	nums = {1,3,1,3,1,3,1,3};
	res = true;
	casenum = 3;

	TESTCASE_p1(makesquare, nums, res, casenum);


	nums = {1,2,3,1,2,3,1,1,4,1,1,4};
	res = true;
	casenum = 4;
	TESTCASE_p1(makesquare, nums, res, casenum);


	nums = {1,2,1,2,3,3,1,1,4,1,1,4};
	res = true;
	casenum = 5;
	TESTCASE_p1(makesquare, nums, res, casenum);


	nums = {2,4,1,1,1,1,2,1,1,4,3,3};
	res = true;
	casenum = 5;
	TESTCASE_p1(makesquare, nums, res, casenum);


	nums = {4,3,3,3,3};
	res = false;
	casenum = 6;
	TESTCASE_p1(makesquare, nums, res, casenum);


	nums = {1,1,2,2,3,3,4,4};
	res = true;
	casenum = 7;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {1,2,2,1,2,5,5,1,6};
	res = false;
	casenum = 8;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {1,2,2,1,2,5,5,1,5};
	res = true;
	casenum = 9;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {1,1,1,1};
	res = true;
	casenum = 10;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {2,2,2,2};
	res = true;
	casenum = 11;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {20,20,20,20};
	res = true;
	casenum = 12;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {20,10,10,20,10,5,5};
	res = true;
	casenum = 13;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {2,1,1,2,1};
	res = false;
	casenum = 14;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {2,1,1,5,2,1};
	res = false;
	casenum = 15;
	TESTCASE_p1(makesquare, nums, res, casenum);

	nums = {5,5,5,5,4,4,4,4,3,3,3,3};
	res = true;
	casenum = 16;
	TESTCASE_p1(makesquare, nums, res, casenum);

}

