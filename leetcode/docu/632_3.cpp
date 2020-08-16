#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <unistd.h>

using namespace std;


class Solution {
public:
	vector<int> smallestRange(vector<vector<int>> & nums)
	{
		vector<int> res;
		int range = INT_MAX;

		int total = 0;
		int k = nums.size();
		for(auto & x : nums)
		{
			total += x.size();
		}

		vector<int> sorted_nums;
		vector<int> k_index;

		{
			vector<int> poses(k, 0);
			for(int i = 0; i < total; i++)
			{
				int smallest = INT_MAX, first_pos, second_pos;
				for(int j = 0; j < k; j++)
				{
					second_pos = poses[j];
					if(second_pos < nums[j].size()
							&& smallest > nums[j][second_pos])
					{
						first_pos = j;
						smallest = nums[j][second_pos];
					}
				}
				poses[first_pos]++;
				k_index.push_back(first_pos);
				sorted_nums.push_back(smallest);
			}

//			show_vector(poses);
		}

//		cout << "sorted_nums: ";
//		show_vector(sorted_nums);

//		cout << "k_inexes: ";
//		show_vector(k_index);

		set<int> k_index_set;
		vector<int> sorted_index(k);

		for(int i = 0; i < k_index.size(); i++ )
		{
			sorted_index[k_index[i]] = i;
			k_index_set.insert(k_index[i]);

			if(k_index_set.size() == k)
			{
				int min = getSmallest(sorted_index);
				int max = getLargest(sorted_index);

				if(range > sorted_nums[max] - sorted_nums[min])
				{
					vector<int> tr{sorted_nums[min], sorted_nums[max]};
					res = tr;
					range = sorted_nums[max] - sorted_nums[min];
				}
//				cout << "2, k_index_set : ";
//				show_set(k_index_set);

//				cout << "2, sorted_index : ";
//				show_vector(sorted_index);

				k_index_set.erase(k_index[min]);

			}
		}
		/*
		*/

		return res;
	}

	void show_set(set<int> & s)
	{
		for(auto & x : s)
		{
			cout << x << ", ";
		}
		cout << "\n";
	}

	int getLargest(vector<int> &vi)
	{
		int max = vi[0];
		for(auto & x : vi)
		{
			if(max < x)
			{
				max = x;
			}
		}
		return max;
	}

	int getSmallest(vector<int> &vi)
	{
		int min = vi[0];
		for(auto & x : vi)
		{
			if(min > x)
			{
				min = x;
			}
		}
		return min;
	}

	void show_vector(vector<int> &vi)
	{
		for(auto & i : vi)
		{
			cout << i << ", ";
		}
		cout << "\n";
	}
};



int main()
{
	vector<vector<int>> nums {{0, 9, 12,20}, {4,10,15,24,26}, {5,18,22,30}};
	Solution s;

	vector<int> range = s.smallestRange(nums);
	for(auto x : range)
	{
		cout << x << "  ";
	}
	cout << "\n";


	vector<vector<int>> nums2 {{0, 0, 9, 9, 12, 12, 20}, {4, 4, 10, 10, 15, 15, 24, 24, 26}, {5, 5, 18, 18, 22, 22, 30}};
	range = s.smallestRange(nums2);
	for(auto x : range)
	{
		cout << x << "  ";
	}
	cout << "\n";

	vector<vector<int>> nums3 {{10,10,13,14,14}, {11,11,16,16}};
	range = s.smallestRange(nums3);
	for(auto x : range)
	{
		cout << x << "  ";
	}
	cout << "\n";

	vector<vector<int>> nums4 {
		{11,38,83,84,84,85,88,89,89,92},
		{28,61,89},
		{52,77,79,80,81},
		{21,25,26,26,26,27},
		{9,83,85,90},
		{84,85,87},
		{26,68,70,71},
		{36,40,41,42,45},
		{-34,21},
		{-28,-28,-23,1,13,21,28,37,37,38},
		{-74,1,2,22,33,35,43,45},
		{54,96,98,98,99},
		{43,54,60,65,71,75},
		{43,46},
		{50,50,58,67,69},
		{7,14,15},
		{78,80,89,89,90},
		{35,47,63,69,77,92,94}};
	range = s.smallestRange(nums4);
	for(auto x : range)
	{
		cout << x << "  ";
	}
	cout << "\n";

#include "testcase"

	range = s.smallestRange(nums5);
	for(auto x : range)
	{
		cout << x << "  ";
	}
	cout << "\n";











	/*
	*/

}



