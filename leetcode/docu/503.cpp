#include "cpp_header.h"

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums)
	{
		vector<int> res(nums.size(), -1);
		int j, k;

		for(int i = 0; i < nums.size(); i++)
		{
			k = i+1;
			for(j=0; j<nums.size(); j++, k++)
			{
				k %= nums.size();

				if(nums[k] > nums[i]){
					res[i] = nums[k];
					break;
				}
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums {1,2,1};

	vector<int> res;

	res = s.nextGreaterElements(nums);

	for(auto x : res)
		cout << x << " ";
	cout << "\n";


}

