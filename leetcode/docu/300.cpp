#include "cpp_header.h"

class Solution {
public:
	int lengthOfLIS(vector<int>& nums)
	{
		vector<int> lens(nums.size(), 1);
		int longest = 0;

		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(nums[i] > nums[j])
				{
					lens[i] = max(lens[i], lens[j] + 1);
				}
			}
			if(longest < lens[i])
			{
				longest = lens[i];
			}
		}

		return longest;
	}

	int lengthOfLIS2(vector<int>& nums)
	{
		if(nums.size() < 2)
			return nums.size();

		// sorted sub sequence of nums
		// it is one of the longest sub increasing sub sequence
		// which has minimum minus of the biggest and smallest.
		vector<int> lis;

		for(auto & num : nums)
		{
			// position in lis that greater or equal than num
			auto idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
			if(idx >= lis.size())
				lis.push_back(num);
			else
				lis[idx] = num;
		}

		for(auto x : lis)
			cout << x << " ";
		cout << "\n";

		return lis.size();
	}


};

int testcase(vector<int> nums, int res, int casenum)
{
	Solution sol;

	if(sol.lengthOfLIS2(nums) == res)
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
	vector<int> nums;
	int res;
	int casenum;

	nums = {10, 9, 2, 5, 3, 7, 101, 18};
	res = 4;
	casenum = 1;
	testcase(nums, res, casenum);
}


