#include "cpp_header.h"

class Solution {
public:
	bool find132pattern(vector<int>& nums)
	{
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				for(int k = j + 1; k < nums.size(); k++)
				{
					if(nums[i] < nums[k] && nums[k] < nums[j])
					{
						return true;
					}
				}
			}
		}

		return false;
	}

	bool find132pattern2(vector<int>& nums)
	{
		vector<int> upper(nums.size(), INT_MIN);

		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				if(nums[j] > upper[i])
				{
					upper[i] = nums[j];
				}
				else if(nums[j] < upper[i] && nums[j] > nums[i])
				{
					return true;
				}
			}
		}
		return false;
	}

	bool find132pattern3(vector<int>& nums)
	{
		if(nums.size() < 3)
			return false;
		stack<int> sta;
		vector<int> min_nums(nums.size());
		min_nums[0] = nums[0];
		for(int i = 1; i < nums.size(); i++)
			min_nums[i] = min(min_nums[i-1], nums[i]);
		for(int j = nums.size() - 1; j >= 0; j--)
		{
			if(nums[j] > min_nums[j])
			{
				while(!sta.empty() && sta.top() <= min_nums[j])
					sta.pop();
				if(!sta.empty() && sta.top() < nums[j])
					return true;
				sta.push(nums[j]);
			}
		}

		return false;
	}



	bool find132pattern4(vector<int>& nums)
	{
		if(nums.size() < 3)
			return false;

		vector<int> min_nums(nums.size());
		min_nums[0] = nums[0];
		for(int i = 1; i < nums.size(); i++)
			min_nums[i] = min(min_nums[i-1], nums[i]);

		set<int> j_set;
		for(int j = nums.size() - 1; j >= 0; j--)
		{
			if(nums[j] > min_nums[j])
			{
				while(!j_set.empty() && (*j_set.begin()) <= min_nums[j])
					j_set.erase(*j_set.begin());
				if(!j_set.empty() && *j_set.begin() < nums[j])
					return true;
				j_set.insert(nums[j]);
			}
		}

		return false;
	}
};

int testcase(vector<int>& nums, bool res, int casenum)
{
	Solution sol;
	if(sol.find132pattern4(nums) == res)
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
	bool res;
	int casenum;

	nums = {1,2,3,4};
	res = false;
	casenum = 1;

	testcase(nums, res, casenum);

	nums = {3,1,2,4};
	res = false;
	casenum = 2;

	testcase(nums, res, casenum);

	nums = {3,1,4,2};
	res = true;
	casenum = 3;

	testcase(nums, res, casenum);

	nums = {-1,3,2,0};
	res = true;
	casenum = 4;

	testcase(nums, res, casenum);

	nums = {-1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,100,101,102,103,104,105,106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 300, 250};
	res = true;
	casenum = 5;

	testcase(nums, res, casenum);


#include "456_testcase"
	res = true;
	casenum = 6;

	testcase(nums, res, casenum);

#include "456_testcase2"
	res = true;
	casenum = 7;

	testcase(nums, res, casenum);



}
