#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
	int leastInterval(vector<char>& tasks, int n)
	{
		map<char, int> tasknums;

		map<char, int> forbidstep;
		unordered_set<char> unforbided;
		multimap<int, char, greater<int>> taskmax;

		int count = tasks.size();

		for(auto c : tasks)
		{
			tasknums[c]++;
		}

		for(auto x : tasknums)
		{
			taskmax.emplace(x.second, x.first);
			unforbided.insert(x.first);
			forbidstep[x.first] = 0;
		}

		int stepcount = 0;

		/*
		for(auto x : tasknums)
		{
			cout << x.first << ":" << x.second << "\n";
		}
		for(auto x : unforbided)
		{
			cout << x << "\n";
		}
		for(auto x : forbidstep)
		{
			cout << x.first << ":" << x.second << "\n";
		}
		*/

		while(count)
		{
			// select on task from unforbided set
			char c = -1;
			if(unforbided.size() > 0)
			{
				for(auto x = taskmax.begin(); x != taskmax.end(); x++)
				{
					if(unforbided.find(x->second) != unforbided.end())
					{
						c = x->second;
						int n = x->first;
						taskmax.erase(x);
						if(n > 1)
						{
							taskmax.emplace(n-1, c);
						}
						else
						{
						}
						break;
					}
				}

				tasknums[c]--;
				forbidstep[c] = n;
				unforbided.erase(c);
				count--;
//				cout << "select " << c << "\n";
			}
			else
			{
//				cout << "select NULL\n";
			}
			for(auto it = forbidstep.begin(); 
					it != forbidstep.end();
					it++)
			{
				if(it->first != c)
				{
					if(it->second > 0)
					{
						// update forbidstep
						it->second--;
					}
				}
				if(it->second == 0)
				{
					// update unforbided set
					unforbided.insert(it->first);
				}
			}
			if(c != -1 && tasknums[c] == 0)
			{
				tasknums.erase(c);
				forbidstep.erase(c);
				unforbided.erase(c);
			}

			/*
			taskmax.clear();
			for(auto x : tasknums)
			{
				taskmax.emplace(x.second, x.first);
			}
			*/

			stepcount++;

			/*
			cout << "--------------------------------------------\n";
			for(auto x : tasknums)
			{
				cout << "tasknum:" << x.first << ":" << x.second << "\n";
			}
			for(auto x : unforbided)
			{
				cout << "unforbided:" << x << "\n";
			}
			for(auto x : forbidstep)
			{
				cout << "forbidstep:" << x.first << ":" << x.second << "\n";
			}
			cout << "--------------------------------------------\n";
			*/


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

#include "621_task"
	n = 36;
	cout << s.leastInterval(task10,n ) << "\n";

#include "621_task11"
	n = 34;
	cout << s.leastInterval(task11, n) << "\n";

}




