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
		do{
			del = 0;
			for(int i = 0; i < senate.size(); i++){
				int cdel = 0;
				if(senate[i] == 'R'){
					for(int j = i + 1; j < senate.size(); j++){
						if(senate[j] == 'D'){
							senate.erase(senate.begin() + j);
							cdel = 1;
							break;
						}
					}
					if(cdel == 0)
					{
						for(int j = 0; j < i; j++){
							if(senate[j] == 'D'){
								senate.erase(senate.begin() + j);
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
						if(senate[j] == 'R'){
							senate.erase(senate.begin() + j);
							cdel = 1;
							break;
						}
					}
					if(cdel == 0){
						for(int j = 0; j < i; j++){
							if(senate[j] == 'R') {
								senate.erase(senate.begin() + j);
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
		} while(del == 1);

		string res;
		if(senate[0] == 'R'){
			res = "Radiant";
		}
		else {
			res = "Dire";
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

