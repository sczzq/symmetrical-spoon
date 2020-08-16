#include "cpp_header.h"

class Solution {
	/*
	struct KeyHash {
		size_t operator()(const int &k) const
		{
			return k;
		}
	};
	struct KeyEqual {
		bool operator()(const int & lhs, const int & rhs) const {
			return lhs == rhs;
		}
	};
	*/

public:
	int findMaxLength(vector<int>& nums)
	{
		int size = nums.size();

		map<int, int> count_index;
		count_index.emplace(0, -1);

		int res = 0;
		int count = 0;

		for(int i = 0;i < nums.size(); i++)
		{
			if(nums[i] == 1) count++;
			else count--;
			if(count_index.find(count) != count_index.end())
			{
				res = max(res, i - count_index[count]);
			}
			else
			{
				count_index.emplace(count, i);
			}

		}

		return res;
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

