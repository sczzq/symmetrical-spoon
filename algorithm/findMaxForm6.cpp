#include <string> // string
#include <iostream>
#include <utility>  // pair, make_pair
#include <algorithm> // sort
#include <vector> // vector
using namespace std;
class Solution {
	struct myclass {
		  bool operator() (string i,string j) { return (i.length()<j.length());}
	} myobject;
public:
	bool mycompare(string& a, string& b){
		return (a.length() < b.length());
	}

    int findMaxForm(vector<string>& strs, int m, int n) {
		vector<string> mstrs(strs);
		vector<int> marked;
		sort(mstrs.begin(), mstrs.end(), myobject);
		for(int i = 0; i < mstrs.size(); i++){
			string& str = mstrs[i];
			if(str.length() <= (m+n)){
				pair<int, int> pai = getPair(str);
				if(pai.first <= m && pai.second <= n){
					marked.push_back(i);
					m -= pai.first;
					n -= pai.second;
				}
			} else
				break;
		}
		return marked.size();
    }

private:
	pair<int, int> getPair(string& str){
		int zeros = 0, ones = 0;
		pair<int, int> p;
		for(char x : str){
			if(x == '0')
				zeros++; 
			else if (x == '1')
				ones++;
		}
		return p = std::make_pair(zeros, ones);
	}
};

int main(){
	vector<string> strs{"00", "000"};
	int m = 1, n = 10;
	int number = 0;

	Solution s;
	number = s.findMaxForm(strs, m, n);
	cout << number << endl;

	vector<string> strs11{"10", "0", "1"};
	m = 1, n = 1;
	number = s.findMaxForm(strs11, m, n);
	cout << number << endl;

	vector<string> strs1{"10", "0", "1", "0", "1", "0", "1", "11", "0", "1"};
	m = 10, n = 10;
	number = s.findMaxForm(strs1, m, n);
	cout << number << endl;

	vector<string> strs2{"10", "0001", "111001", "1", "0"};
	m = 5, n = 3;
	number = s.findMaxForm(strs2, m, n);
	cout << number << endl;

	vector<string> strs3{"0","1101","01","00111","1","10010","0","0","00","1","11","0011"};
	m = 63, n = 36;
	number = s.findMaxForm(strs3, m, n);
	cout << number << endl;

	vector<string> strs4{"10","0001","111001","1","0"};
	m = 3, n = 4;
	number = s.findMaxForm(strs4, m, n);
	cout << number << endl;

	vector<string> strs5{"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
	m = 9, n = 80;
	number = s.findMaxForm(strs5, m, n);
	cout << number << endl;

	vector<string> strs6{"111","1000","1000","1000"};
	m = 9, n = 3;
	number = s.findMaxForm(strs6, m, n);
	cout << number << endl;

	return 0;
}
