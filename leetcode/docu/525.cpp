#include "cpp_header.h"

class Solution {
public:
	int findMaxLength(vector<int>& nums)
	{
		int res_sum = 0;

		int zero_count = 0, one_count = 0;
		for(auto & n : nums)
		{
			if(n == 0)
			{
				zero_count++;
			}
			else
			{
				one_count++;
			}
		}

		for(int i = 0; i < nums.size(); i++)
		{
			pair<int, int> cur;
			if(nums[i] == 0)
			{
				cur = make_pair(1, 0);
			}
			else
			{
				cur = make_pair(0, 1);
			}
			for(int j = i + 1; j < nums.size(); j++)
			{
				if(nums[j] == 0)
				{
					cur.first++;
				}
				else
				{
					cur.second++;
				}
				if(cur.first == cur.second
						&& res_sum < (cur.first+cur.second))
				{
					res_sum = cur.first * 2;
				}
			}
			if(res_sum >= (nums.size() - i))
			{
				break;
			}
			if(res_sum >= (zero_count * 2)
					|| res_sum >= (one_count * 2))
			{
				break;
			}
		}

		return res_sum;
	}
};

void testcase(vector<int> nums, int res, int casenum)
{
	Solution sol;

	cout << "------------\n";
	if(sol.findMaxLength(nums) == res)
	{
		cout << casenum << " passed\n";
	}
	else
	{
		cout << casenum << " no pass\n";
		cout << "detail: \n";
		for(auto x : nums)
		{
			cout << x << "  ";
		}
		cout << "\n";
	}
	cout << "-----------------------------------\n";
}

int main()
{
	vector<int> nums;
	int res;
	int casenum;

	nums = {0, 1};
	res = 2;
	casenum = 1;

	testcase(nums, res, casenum);

	nums = {0, 1, 0};
	res = 2;
	casenum = 2;

	testcase(nums, res, casenum);

	nums = {0, 1, 0, 0, 0};
	res = 2;
	casenum = 3;

	testcase(nums, res, casenum);

	nums = {0, 0, 0, 0};
	res = 0;
	casenum = 4;

	testcase(nums, res, casenum);

	nums = {};
	res = 0;
	casenum = 6;

	testcase(nums, res, casenum);

	nums = {0};
	res = 0;
	casenum = 7;

	testcase(nums, res, casenum);

	nums = {0, 0};
	res = 0;
	casenum = 8;

	testcase(nums, res, casenum);

	nums = {0, 0, 1, 1};
	res = 4;
	casenum = 9;

	testcase(nums, res, casenum);

	nums = {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1};
	res = 4;
	casenum = 10;

	testcase(nums, res, casenum);

}

