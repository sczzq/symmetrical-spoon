#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <unistd.h>

using namespace std;

struct MMap{
	int num;
	int pos; // first position in nums
};


class Solution {
public:
	vector<int> smallestRange(vector<vector<int>> & nums)
	{
		vector<int> res;
		int range = INT_MAX;

		vector<int> poses(nums.size(), 0);
		int full_num = 0;

		int first_pos = 0;
		vector<MMap> tres;
		vector<MMap> seq;
		set<int> tset; 

		while(tset.size() != nums.size())
		{
			int second_pos;
			int smallest = INT_MAX;
			for(int i = 0; i < nums.size(); i++)
			{
				second_pos = poses[i];
				if(second_pos < nums[i].size()
						&& smallest > nums[i][second_pos])
				{
					smallest = nums[i][second_pos];
					first_pos = i;
				}
			}

			if(smallest == INT_MAX)
			{
				break;
			}

			MMap mm{smallest, first_pos};
			poses[first_pos]++;

			if(tset.size() == nums.size())
			{
				cout << "erase tset " << seq[0].pos << "\n";
				tset.erase(seq[0].pos);
				if(seq.size() >= nums.size())
				{
					cout << "erase seq first ele : " << seq[0].pos << " -->> " << seq[0].num << "\n";
					seq.erase(seq.begin());
				}
			}
			for(auto x : seq)
			{
				cout << x.pos << " : " << x.num << "; ";
			}
			cout << "\n";

			for(auto x : tset )
			{
				cout << x << "  ";
			}
			cout << "\n";

			seq.push_back(mm);
			tset.insert(first_pos);
			cout << "1, insert " << first_pos << " -->> " << smallest << "\n";
			cout << "tset size : " << tset.size() << "\n";
			cout << "seq size : " << seq.size() << "\n";
		}

		int largest = seq[seq.size()-1].num;
		int smallest = seq[0].num;
		if(largest - smallest < range)
		{
			range = largest - smallest;
			tres = seq;
		}

		int full_nums = 0;
		// update one element each iterate
		while(1)
		{
			int smallest = INT_MAX;
			tset.erase(seq[0].pos);

			while(tset.size() != nums.size() )
			{
				int first_pos, second_pos;
				smallest = INT_MAX;
				for(int i = 0; i < nums.size(); i++)
				{
					second_pos = poses[i];
					if(second_pos < nums[i].size()
							&& smallest > nums[i][second_pos]){
						smallest = nums[i][second_pos];
						first_pos = i;
					}
				}

				if(smallest == INT_MAX)
				{
					break;
				}

				MMap mm{smallest, first_pos};
				poses[first_pos]++;

				if(seq.size() == nums.size())
				{
					cout << "erase in seq: " << seq[0].pos << " -->> " << seq[0].num << "\n";
					seq.erase(seq.begin());
				}

				seq.push_back(mm);
				tset.insert(first_pos);
				cout << "insert to seq : " << first_pos <<  "-->>" << smallest << "\n";
			}

			if(smallest == INT_MAX)
			{
				break;
			}

			int largest = seq[seq.size()-1].num;
			smallest = seq[0].num;
			if(largest - smallest < range)
			{
				range = largest - smallest;
				tres = seq;
			}
		}
		for(auto & x : tres)
		{
			res.push_back(x.num);
		}

		return res;
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

	/*
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
	*/

}



