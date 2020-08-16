#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Task{
	char id;
	int nums;
	int forbidstep;
};


class Solution {
public:
	int leastInterval(vector<char>& tasks, int n)
	{
		map<char, int> tasknums;
		multimap<int, Task, greater<int>> mtask;

		int count = tasks.size();

		for(auto c : tasks)
		{
			tasknums[c]++;
		}

		for(auto x : tasknums)
		{
			Task t;
			t.id = x.first;
			t.nums = x.second;
			t.forbidstep = 0;

			mtask.emplace(t.nums, t);
		}

		int stepcount = 0;

		while(mtask.size() > 0)
		{
			Task ct;
			auto eit = mtask.end();
			for(auto it = mtask.begin(); it != mtask.end(); it++)
			{
				Task &t = it->second;
//				cout << "current        " << t.id << ", " << t.nums << ", " << t.forbidstep << "\n";
				if(t.forbidstep == 0)
				{
					if(eit == mtask.end() && t.nums > 0 )
					{
						ct = t;
						eit = it;
					}
				}
				else if(t.forbidstep > 0)
				{
					t.forbidstep--;
				}
			}
			if(eit != mtask.end())
			{
//				cout << "select " << ct.id << ", " << ct.nums << ", " << ct.forbidstep << "\n";
				mtask.erase(eit);
				if(ct.nums > 1)
				{
					ct.nums--;
					ct.forbidstep = n;
					mtask.emplace(ct.nums, ct);
				}
			}
			else
			{
//				cout << "select NULL\n";
			}
			stepcount++;
		}
		return stepcount;
	}
};


int main()
{
	vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
	int n = 2;

	Solution s;
	int stepcount = s.leastInterval(tasks, n);
	cout << stepcount << "\n";

	vector<char> tasks2{'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H', 'I', 'I', 'J', 'J', 'K', 'K', 'L', 'L', 'M', 'M', 'N', 'N', 'O', 'O', 'P', 'P', 'Q', 'Q', 'R', 'R', 'S', 'S', 'T', 'T', 'U', 'U', 'V', 'V', 'W', 'W', 'X', 'X', 'Y', 'Y', 'Z', 'Z'};
	//cout << s.leastInterval(tasks2, n) << "\n";
	//

	vector<char> tasks3{'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D'};
	cout << s.leastInterval(tasks3,n ) << "\n";

	vector<char> task4{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D' , 'E', 'F', 'G'};
	cout << s.leastInterval(task4,n ) << "\n";

	vector<char> task5{'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D' , 'E', 'F', 'G'};
	cout << s.leastInterval(task5,n ) << "\n";

	/*
	*/
#include "621_task"
	n = 36;
	cout << s.leastInterval(task10,n ) << "\n";

#include "621_task11"
	n = 34;
	cout << s.leastInterval(task11, n) << "\n";

}




