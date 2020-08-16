#include "cpp_header.h"

/*
 * 平均数的绝对差不是最小
 * 绝对离差之和, 最小, 
 *
 * 中位数的离差绝对值之和最小
 * 平均数的离差平方和最小
 *
 */

class Solution {
public:
	int minMove2(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());

		int min_move = 0;

		for(int i = 0; i < nums.size(); i++)
		{
			min_move += abs(nums[nums.size() / 2] - nums[i]);
		}

		return min_move;
	}
};

int main()
{
	vector<int> nums;
	int res;
	
	nums = {1,2,3};
	res = 2;

	Solution sol;

	cout << sol.minMove2(nums) << "\n";
}


