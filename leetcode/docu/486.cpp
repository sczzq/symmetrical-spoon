#include "cpp_header.h"

class Solution {
public:
	bool predictTheWinner(vector<int>& nums)
	{
		return getNext(nums, 0, nums.size()-1, 0, 0, true);
	}

	int getNext(vector<int>& nums, int left, int right, int p1_score, int p2_score,  bool is_p1)
	{
		if(left > right)
			return p1_score >= p2_score;
		if(is_p1)
			return getNext(nums, left + 1, right, p1_score + nums[left], p2_score, false)
				|| getNext(nums, left, right - 1, p1_score + nums[right], p2_score, false);
		else
			return getNext(nums, left + 1, right, p1_score, p2_score + nums[left], true)
				&& getNext(nums, left, right - 1, p1_score, p2_score + nums[right], true);
	}

	/*
	 * dp[i][j].first, is nums[i] to nums[j] the max score of first hand 
	 * dp[i][j].second, is nums[i] to nums[j] the max score of second hand
	 *
	 * so
	 * dp[i][j].first = max(nums[i] + dp[i+1][j].second, nums[j] + dp[i][j-1].second)
	 *
	 * dp[i][j].second = max(nums[i] + dp[i+1][j].first, nums[j] +  dp[i][j-1].first)
	 *
	 *
	 */

	bool predictTheWinner2(vector<int>& nums)
	{
		vector<vector<pair<int, int>>>
			dp
			(
				nums.size(),
				vector<pair<int, int>>
				(
				 nums.size(),
				 pair<int, int>(0, 0)
				)
			);
		for(int i = 0; i < nums.size(); i++)
			dp[i][i].first = nums[i];

		for(int i = nums.size() - 2; i >= 0; i--)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				int left = nums[i] + dp[i+1][j].second;
				int right = nums[j] + dp[i][j-1].second;
				if(left > right)
				{
					dp[i][j].first = left;
					dp[i][j].second = dp[i+1][j].first;
				}
				else
				{
					dp[i][j].first = right;
					dp[i][j].second = dp[i][j-1].first;
				}
			}
		}

		return dp[0][nums.size() - 1].first >= dp[0][nums.size()-1].second;
	}


	bool predictTheWinner3(vector<int>& nums)
	{
		vector<pair<int, int>> dp(nums.size(), pair<int, int>(0,0));
		for(int i = 0; i < nums.size(); i++)
			dp[i].first = nums[i];
		for(int i = nums.size()-2; i>=0; i--)
			for(int j = i + 1; j < nums.size(); j++)
			{
				int left = nums[i] + dp[j].second;
				int right = nums[j] + dp[j-1].second;
				if(left > right)
				{
					dp[j].first = left;
					dp[j].second = dp[j].first;
				}
				else
				{
					dp[j].first = right;
					dp[j].second = dp[j-1].first;
				}
			}

		return dp[nums.size() - 1].first >= dp[nums.size() - 1].second;
	}


	/*
	 * dp[i][j] is the minus score of first hand and second hand between i and j
	 *
	 * dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])
	 *
	 * space complexcity from O(2n) to O(n)
	 *
	 */
	bool predictTheWinner4(vector<int>& nums)
	{
		vector<int> dp = nums;
		for(int i = nums.size() - 2; i >= 0; i--)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				dp[j] = max(nums[i]-dp[j], nums[j] - dp[j-1]);
			}
		}
		return dp.back() >= 0;
	}




	/*
	 * dp[i][j].first, is nums[i] to nums[j] the max score of first hand 
	 * dp[i][j].second, is nums[i] to nums[j] the max score of second hand
	 *
	 * so
	 * dp[i][j].first = max(nums[i] + dp[i+1][j].second, nums[j] + dp[i][j-1].second)
	 *
	 * dp[i][j].second = max(nums[i] + dp[i+1][j].first, nums[j] +  dp[i][j-1].first)
	 *
	 * same to predictTheWinner2, just change sequence of cycle, i: 1 -> nums.size() - 1
	 *
	 */

	bool predictTheWinner5(vector<int>& nums)
	{
		vector<vector<pair<int, int>>>
			dp
			(
				nums.size(),
				vector<pair<int, int>>
				(
				 nums.size(),
				 pair<int, int>(0, 0)
				)
			);
		for(int i = 0; i < nums.size(); i++)
			dp[i][i].first = nums[i];

		for(int j = 1; j < nums.size(); j++)
		{
			for(int i = j - 1; i >= 0; i--)
			{
				int left = nums[i] + dp[i+1][j].second;
				int right = nums[j] + dp[i][j-1].second;
				if(left > right)
				{
					dp[i][j].first = left;
					dp[i][j].second = dp[i+1][j].first;
				}
				else
				{
					dp[i][j].first = right;
					dp[i][j].second = dp[i][j-1].first;
				}
			}
		}

		return dp[0][nums.size() - 1].first >= dp[0][nums.size()-1].second;
	}



};

int main()
{
	vector<int> nums;
	int res;
	int casenum;

	nums = {1,5,2};
	res = false;
	casenum = 1;
	TESTCASE_p1(predictTheWinner4, nums, res, casenum);

	
	nums = {1,5,233,7};
	res = true;
	casenum = 2;
	TESTCASE_p1(predictTheWinner4, nums, res, casenum);

#include "456_testcase"
	res = true;
	casenum = 3;
	TESTCASE_p1(predictTheWinner4, nums, res, casenum);


}
