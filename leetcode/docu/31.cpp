#include "cpp_header.h"

class Solution {
public:
	void nextPermutation(vector<int>& nums)
	{
		int i = -1, k = -1;
		for(int j = nums.size() - 1; j > 0; j--)
		{
			if(nums[j-1]<nums[j])
			{
				i = j - 1;
				break;
			}
		}

		//
		if(i == -1)
		{
			nixu(nums, 0, nums.size() -1);
			return;
		}

		for(int j = nums.size() - 1; j >= 0; j--)
		{
			if(nums[i] < nums[j])
			{
				k = j;
				break;
			}
		}

		int t = nums[i];
		nums[i] = nums[k];
		nums[k] = t;

		nixu(nums, i+1, nums.size() - 1);
	}

	void nixu(vector<int>& nums, int i, int j)
	{
		while(i<j)
		{
			int t = nums[i];
			nums[i] = nums[j];
			nums[j] = t;
			i++;
			j--;
		}
	}
};
/*
 * 1 2 3 -> 1 3 2 -> 2 1 3 -> 2 3 1 -> 3 1 2 -> 3 2 1
 * 
 *
 */

void show_vector(vector<int> nums)
{
	for(auto i : nums)
		cout << i << " ";
	cout << "\n";
}

void stlll(vector<int>& nums)
{
	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);

	next_permutation(nums.begin(), nums.end());
	show_vector(nums);
}

void solu(vector<int>& nums)
{
	Solution sol;
	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

	sol.nextPermutation(nums);
	show_vector(nums);

}

int main()
{
	vector<int> nums, nums2;
	int casenum;

	nums = {1, 2, 3, 4, 5};
	show_vector(nums);

	nums2 = nums;

	stlll(nums);

	cout << "-----------------------------------\n";

	solu(nums2);

}
