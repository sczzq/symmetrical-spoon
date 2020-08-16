#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	string predictPartyVictory(string senate)
	{
		string res;

		vector<int> people(2, 0), bans(2, 0);
		queue<int> que;

		for(auto c : senate)
		{
			int x = c == 'R' ? 1 : 0;
			people[x]++;
			que.push(x);
		}

		int i = 0;
		while(people[0] > 0 && people[1] > 0)
		{
			int x = que.front();
			que.pop();
			if(bans[x] > 0) {
				bans[x]--;
				people[x]--;
			} else {
				bans[x^1]++;
				que.push(x);
			}
		}

		return people[1] > 0 ? "Radiant" : "Dire";
	}
};


