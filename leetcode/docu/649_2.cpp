#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string predictPartyVictory (string senate)
	{
		int del = 0;
		cout << senate << "\n";
		vector<int> mark(senate.size(), 0);
		do{
			del = 0;
			for(int i = 0; i < senate.size(); i++){
				int cdel = 0;
				cout << i << ", ";
				for(int i = 0; i < senate.length(); i++)
				{
					cout << mark[i] << " ";
				}
				cout << "\n";
				if(mark[i] == 0)
				{
					if(senate[i] == 'R'){
						for(int j = i + 1; j < senate.size(); j++){
							if(senate[j] == 'D' && mark[j] == 0){
	//							senate.erase(senate.begin() + j);
								mark[j] = 1;
								cdel = 1;
								break;
							}
						}
						if(cdel == 0)
						{
							for(int j = 0; j < i; j++){
								if(senate[j] == 'D' && mark[j] == 0){
	//								senate.erase(senate.begin() + j);
									mark[j] = 1;
									cdel = 1;
									break;
								}
							}
						}
					}
					else // 'D'
					{
						for(int j = i + 1; j < senate.size(); j++)
						{
							if(senate[j] == 'R' && mark[j] == 0){
	//							senate.erase(senate.begin() + j);
								mark[j] = 1;
								cdel = 1;
								break;
							}
						}
						if(cdel == 0){
							for(int j = 0; j < i; j++){
								if(senate[j] == 'R' && mark[j] == 0) {
	//								senate.erase(senate.begin() + j);
									mark[j] = 1;
									cdel = 1;
									break;
								}
							}
						}
					}
					if(cdel == 1)
					{
						del = 1;
					}
				}
				cout << i << ", ";
				for(int i = 0; i < senate.length(); i++)
				{
					cout << mark[i] << " ";
				}
				cout << "\n";
				cout << "----------------------------------------------------------\n";
			}
		} while(del == 1);

		string res;
		for(int i = 0; i < senate.length(); i++)
		{
			if(mark[i] == 0) {
				if(senate[i] == 'R'){
					res = "Radiant";
				}
				else {
					res = "Dire";
				}
				break;
			}
		}

		return res;
	}
};


int main(){
	Solution s;

	string ss{"RDDRRDD"};
//	cout << s.predictPartyVictory(ss) << "\n";

	ss = {"DRRDRDRDRDDRDRDR"};
	cout << s.predictPartyVictory(ss) << "\n";
}

