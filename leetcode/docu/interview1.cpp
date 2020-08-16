#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int> &nums1, int m , vector<int> &nums2, int n)
	{
		vector<int> res(nums1.size());
		int i = 0, j = 0;
		while( i < m && j < n  )
		{
			if(nums1[i] < nums2[j])
			{
				res[i+j] = nums1[i];
				i++;
			}
			else
			{
				res[i+j] = nums2[j];
				j++;
			}
		}
		while(i < m)
		{
			res[i+j] = nums1[i];
			i++;
		}
		while(j < n)
		{
			res[i+j] = nums2[j];
			j++;
		}

		nums1 = res;
	}
};

int main()
{
	vector<int> nums1{1,2,3,0,0,0};
	vector<int> nums2{2,5,6};
	int m = 3, n = 3;

	Solution s;
	s.merge(nums1, m, nums2, n);

	for(auto x : nums1)
		cout << x << " ";
	cout << "\n";
}
