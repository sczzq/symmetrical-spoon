#include "cpp_header.h"

class Solution {
public:
	int totalHammingDistance2(vector<int>& nums)
	{
		map<int, int> memo;
		int res = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				int rr = nums[i] ^ nums[j];
				while(rr > 0)
				{
					if(rr & 1u) res++;
					rr >>= 1;
				}
			}
		}

		cout << res << "\n";

		return res;
	}

	int totalHammingDistance(vector<int>& nums)
	{
		int res = 0;
		for(int i = 0; i < sizeof(int) * 8; i++)
		{
			int zeroes = 0, ones = 0;
			for(int j = 0; j < nums.size(); j++)
			{
				if(nums[j])
				{
					if(nums[j] & (1u)) ones++;
					else	zeroes++;
					nums[j] >>= 1;
				}
				else
				{
					zeroes++;
				}
			}
			res += zeroes * ones;
		}

		return res;
	}

	int totalHammingDistance3(vector<int>& nums)
	{
		int res = 0;
		for(int i = 0; i < sizeof(int) * 8; i++)
		{
			int zeroes = 0, ones = 0;
			for(int j = 0; j < nums.size(); j++)
			{
				if(nums[j] & (1u << i)) ones++;
				else	zeroes++;
			}
			res += zeroes * ones;
		}

		return res;
	}

};

int main()
{
	vector<int> nums;
	int res;
	int casenum;

	nums = {4,14,2};
	res = 6;
	casenum = 1;
	TESTCASE_p1(totalHammingDistance, nums, res, casenum);


#include "456_testcase"
	res = 1439092774;
	casenum = 2;
	TESTCASE_p1(totalHammingDistance, nums, res, casenum);


}

