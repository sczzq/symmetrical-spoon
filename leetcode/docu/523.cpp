#include "cpp_header.h"

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k)
	{
		bool res = false;

		for(int i = 0; i < nums.size(); i++)
		{
			vector<int> sums(nums.size());
			sums[i] = nums[i];
			for(int j = i + 1; j < nums.size(); j++)
			{
				sums[j] = sums[j-1] + nums[j];
				if(k == 0)
				{
					if(sums[j] == 0)
					{
						res = true;
						cout << i << ", " << j << ", sum : " << sums[j] << ", 1\n";
						break;
					}
				}
				else 
				{
					if(sums[j] % k == 0)
					{
						cout << i << ", " << j << ", sum : " << sums[j] << ", 2\n";
						res = true;
						break;
					}
				}
			}
			if(res == true)
			{
				break;
			}
		}
		return res;
	}
};

void testcase(vector<int> & nums, int k, int res, int casenum)
{
	Solution sol;

	if(sol.checkSubarraySum(nums, k) == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
		cout << "details: \n";
		cout << "array : ";
		for(auto x : nums)
		{
			cout << x << ", ";
		}
		cout << "\n";
		cout << "k: " << k << "\n";
	}
	cout << "-----------------------------------------\n";
}

int main()
{
	vector<int> nums {23,2,4,6,7};
	int k = 6;
	testcase(nums, k, true, 1);

	k = 0;
	nums = {23,2,4,6,7};
	testcase(nums, k, false, 2);

	nums = {1,2,3,0,0,5,0};
	k = 0;
	testcase(nums, k, true, 3);

	nums = {1,2,0,5,0};
	k = 0;
	testcase(nums, k, false, 4);

	nums = {1,2,0,5,0,0};
	k = 0;
	testcase(nums, k, true, 5);

	nums = {10,20,0,50,0,0};
	k = -10;
	testcase(nums, k, true, 6);

	nums = {0,0};
	k = -10;
	testcase(nums, k, true, 7);

	nums = {0};
	k = -10;
	testcase(nums, k, false, 8);

	nums = {0,10,20,30,45};
	k = -10;
	testcase(nums, k, true, 9);

	nums = {20,10,20,30,45};
	k = 15;
	testcase(nums, k, true, 10);

	nums = {20};
	k = 10;
	testcase(nums, k, false, 11);

	nums = {20};
	k = 1;
	testcase(nums, k, false, 12);

	nums = {20, 2};
	k = 1;
	testcase(nums, k, true, 13);

	nums = {0, 2};
	k = 1;
	testcase(nums, k, true, 14);


}



