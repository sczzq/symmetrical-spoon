/*************************************************************************
	> File Name: findSeqM.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 25 Apr 2017 08:38:19 PM CST
 ************************************************************************/

#include <iostream>
#include <vector> // vector
using namespace std;

class Solution{
public:
	int findSeqM(vector<int>& seq, int m, vector<int>& result){
		vector<int> cum;
		vector<int> mod;
		cum.push_back(0);

		for(int i=1; i<=seq.size(); i++)
			cum.push_back(seq[i-1]+cum[i-1]);

		for(int i=0; i<cum.size(); i++)
			mod.push_back(cum[i] % m);

		cout << "its cumulate is: ";
		for(int i=0; i<cum.size(); i++)
			cout << cum[i] << ", " ;
		cout << endl;

		int start=0, end=0;
		for(start=1; start<seq.size(); start++){
			for(end=start+1; end<=seq.size(); end++)
				if(mod[start] == mod[end])
					break;
			if(mod[start] == mod[end])
				break;
		}

		if(mod[start] == mod[end]){
			int s = start, e = end;
			while(s < e)
				result.push_back(seq[s++]);
		}

		cout << start << ", " << end << endl;

		return cum[end] - cum[start];
	}
};

int main()
{
	vector<int> seq{2, 3, 5, 6, 5, 6, 4, 2, 8};
	int m = seq.size();

	cout << "init sequence: ";
	for(int i=0; i<seq.size(); i++)
		cout << seq[i] << ", ";
	cout << endl;

	vector<int> result;
	Solution s;

	int sum = s.findSeqM(seq, m, result);

	cout << "its result: " ;
	for(int i=0; i<result.size(); i++)
		cout << result[i] << ", ";
	cout << endl;

	cout << "sum: " << sum << endl;

	return 0;
}
