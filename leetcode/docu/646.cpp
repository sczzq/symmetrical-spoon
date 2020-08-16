#include "cpp_header.h"

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) 
	{
		int least = INT_MIN;
		set<vector<int>> first_pairs;
		set<vector<int>> second_pairs;

		vector<vector<int>> undup_pairs;


		{
			map<int, vector<int>> sorted_first_pairs;
			map<int, vector<int>> sorted_second_pairs;

			for(auto & p : pairs)
			{
				if(sorted_first_pairs.find(p[0]) != sorted_first_pairs.end())
				{
					if(sorted_first_pairs[p[0]][1] > p[1])
					{
						sorted_first_pairs[p[0]] = p;
					}
				}
				else
				{
					sorted_first_pairs.emplace(p[0], p);
				}

				if(sorted_second_pairs.find(p[1]) != sorted_second_pairs.end())
				{
					if(sorted_second_pairs[p[1]][0] < p[0])
					{
						sorted_second_pairs[p[1]] = p;
					}
				}
				else
				{
					sorted_second_pairs.emplace(p[1], p);
				}
			}

			for(auto & sp : sorted_first_pairs)
			{
				first_pairs.insert(sp.second);
			}
			for(auto & sp : sorted_second_pairs)
			{
				second_pairs.insert(sp.second);
			}

			cout << "----------------------------------------\n";
			for(auto & sp : sorted_first_pairs)
			{
				cout << sp.first << " : ";
				for(auto x : sp.second)
				{
					cout << x << ", ";
				}
				cout << "\n";
			}

			cout << "----------------------------------------\n";

			for(auto & sp : sorted_second_pairs)
			{
				cout << sp.first << " : ";
				for(auto x : sp.second)
				{
					cout << x << ", ";
				}
				cout << "\n";
			}
			cout << "----------------------------------------\n";
		}

		{
			for(auto & p : first_pairs)
			{
				if(second_pairs.find(p) != second_pairs.end())
				{
					undup_pairs.push_back(p);
				}
			}
		}

		for(auto & p : undup_pairs)
		{
			for(auto x : p)
			{
				cout << x << " ";
			}
			cout << "\n";
		}
		cout << "----------------------------------------\n";



		// should be get un-contained pairs.
		for(int i = 0; i < undup_pairs.size(); i++)
		{
			vector<int> p = undup_pairs[i];
			for(int j = i + 1; j < undup_pairs.size(); j++)
			{
				if(p[0] <= undup_pairs[j][0] && p[1] >= undup_pairs[j][1])
				{
					undup_pairs.erase(undup_pairs.begin() + i);
					i--;
					break;
				}
			}
		}


		for(auto & p : undup_pairs)
		{
			for(auto x : p)
			{
				cout << x << " ";
			}
			cout << "\n";
		}
		cout << "----------------------------------------\n";



		int last_max = undup_pairs[0][1];
		int count = 1;
		for(int i = 1; i < undup_pairs.size(); i++)
		{
			if(last_max < undup_pairs[i][0])
			{
				count++;
				last_max = undup_pairs[i][1];
			}
		}

		return count;

	}
};

int main()
{
	Solution s;
	vector<vector<int>> pairs{{1,2}, {2,3}, {3,4}};

	cout << s.findLongestChain(pairs) << "\n";

	pairs = {{1,2}, {3,7}, {3,5}, {4,5}, {4,7}, {5,7}, {6,7}, {4, 6}};
	cout << s.findLongestChain(pairs) << "\n";

	pairs = {{1,2}, {3,7}, {3,5}, {4,5}, {4,7}, {5,7}, {6,7}};
	cout << s.findLongestChain(pairs) << "\n";

	pairs = {{1,2}, {3,7}, {3,5},{3,4}, {4,5}, {4,7}, {5,7}, {6,7}};
	cout << s.findLongestChain(pairs) << "\n";

	pairs = {{1,2}};
	cout << s.findLongestChain(pairs) << "\n";

	pairs =	{{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
	cout << s.findLongestChain(pairs) << "\n";

}

