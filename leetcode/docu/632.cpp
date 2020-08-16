#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class MMap {
public:
	int num;
	int pos; // index in nums
};

class Solution {
public:
	vector<int> smallestRange(vector<vector<int>> & nums)
	{
		vector<MMap> sort_nums;
		merge_sort(nums, sort_nums);
		show_merge_sort(sort_nums);

		return getSmallestRange(nums, sort_nums);

	}

	vector<int> getSmallestRange(vector<vector<int>> & nums, 
			vector<MMap> & sort_nums)
	{
		vector<int> res;
		int range = INT_MAX;
		int start = 0;

		while(1)
		{
			vector<MMap> seq;
			set<int> tset;
			for(int i = start; i < sort_nums.size(); i++)
			{
				seq.push_back(sort_nums[i]);
				tset.insert(sort_nums[i].pos);
				if(tset.size() == nums.size())
				{
					start = i;
					break;
				}
				if(seq.size() == nums.size())
				{
					seq.erase(seq.begin());
				}
			}
			if(seq.size() < nums.size())
			{
				break;
			}

			int smallest = INT_MAX, largest = INT_MIN;
			for(auto & s : seq)
			{
				if(s.num < smallest)
				{
					smallest = s.num;
				}
				if(s.num > largest)
				{
					largest = s.num;
				}
			}
			if(largest - smallest < range)
			{
				vector<int> ns{smallest, largest};
				res = ns;
				range = largest - smallest;
			}
		}

		return res;
	}


	void show_merge_sort(vector<MMap> &sort_nums)
	{
		for(auto &mm : sort_nums)
		{
			cout << mm.pos << " : " << mm.num << "\n";
		}
	}

	void merge_sort(vector<vector<int>> & nums,
			vector<MMap> & sort_nums)
	{
		vector<int> poses(nums.size(), 0);
		while(1)
		{
			int smallest = INT_MAX, first_pos = 0;
			int full_num = 0;
			for(int i = 0; i < nums.size(); i++)
			{
				int second_pos = poses[i];
				if(second_pos < nums[i].size()
						&& smallest > nums[i][second_pos]){
					smallest = nums[i][second_pos];
					first_pos = i;
				}
				if(second_pos == nums[i].size())
				{
					full_num++;
				}
			}
			if(full_num == nums.size())
			{
				break;
			}

			poses[first_pos]++;

			MMap mm;
			mm.num = smallest;
			mm.pos = first_pos;
			sort_nums.push_back(mm);
		}
	}
};


int main()
{
	vector<vector<int>> nums {{4,10,15,24,26}, {0, 9, 12,20}, {5,18,22,30}};
	Solution s;

	vector<int> range = s.smallestRange(nums);
	for(auto x : range)
	{
		cout << x << "  ";
	}
	cout << "\n";
}


