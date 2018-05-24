/*************************************************************************
	> File Name: findMaxForm111.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 25 Apr 2017 10:51:49 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
	/*
	 * using dynamic programming.
	 * so, need some more time to do familar with dp. 
	 */
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		cout << "the strings are: ";
		for(string& str : strs)
			cout << str << ",";
		cout << " m: " << m << ", n: " << n;
		cout << endl;
		int dp[m+1][n+1];
		int maxForm[m+1][n+1];
//		int maxForm2[strs.size()+1];
		vector<int> maxForm2;
		for(int i=0; i<=m; i++)
			for(int j=0; j<=n; j++){
				dp[i][j] = 0;
				maxForm[i][j] = -1;
			}
		for (int s=0; s<strs.size(); s++) {
			pair<int, int> count = mcount(strs[s]);
			for (int i=m; i>=count.first; i--) 
				for (int j=n; j>=count.second; j--){
					if(dp[i][j] < 1 + dp[i-count.first][j-count.second]){
						dp[i][j] = 1 + dp[i-count.first][j-count.second];
						maxForm[i][j] = s;
					}
				}
		}
		/*
		int number = 1;
		for(int i=0; i<=m; i++){
			for(int j=0; j<=n; j++){
				if(dp[i][j] == number){
					number++;
					maxForm2.push_back(maxForm[i][j]);
				}
			}
		}
		cout << "the max form strings are: ";
		for(int i : maxForm2){
			cout << strs[i] << ", ";
		}
		cout << endl;
		*/

		/*
		cout << "the max form strings are: ";
		for(int i=m, j=n; j>=0&&i>=0; ){
			if(maxForm[i][j] > -1){
				int s = maxForm[i][j];
				pair<int, int> pai = mcount(strs[s]);
				cout << ":" << dp[i][j] << ":" ;
				cout << strs[s] << ", ";
				i = i - pai.first;
				j = j - pai.second;
			}
			else{
				break;
			}
		}
		cout << endl;
		*/
		/*
		for(int i=0; i<=m; i++){
			cout << i << " ";
			for(int j=0; j<=n; j++){
//				cout << maxForm[i][j] << " ";
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		*/
		return dp[m][n];
	}

	/**
	 *      * 统计0和1的数量
	 *           * */
	pair<int, int> mcount(string& str) {
		pair<int, int> pai;
		int zeroes = 0, ones = 0;
		for(int i=0; i<str.length(); i++)
			if(str[i] == '0')
				zeroes++;
			else
				ones++;
		return pai = make_pair(zeroes, ones);
	}
};


int main()
{
	vector<string> strs{"00", "000"};
	int m = 1, n = 10;
	int number = 0;

	Solution s;
	number = s.findMaxForm(strs, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs11{"10", "0", "1"};
	m = 1, n = 1;
	number = s.findMaxForm(strs11, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs1{"10", "0", "1", "0", "1", "0", "1", "11", "0", "1"};
	m = 10, n = 10;
	number = s.findMaxForm(strs1, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs2{"10", "0001", "111001", "1", "0"};
	m = 5, n = 3;
	number = s.findMaxForm(strs2, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs3{"0","1101","01","00111","1","10010","0","0","00","1","11","0011"};
	m = 63, n = 36;
	number = s.findMaxForm(strs3, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs4{"10","0001","111001","1","0"};
	m = 3, n = 4;
	number = s.findMaxForm(strs4, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs5{"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
	m = 9, n = 80;
	number = s.findMaxForm(strs5, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs6{"111","1000","1000","1000"};
	m = 9, n = 3;
	number = s.findMaxForm(strs6, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs7{"11","1000","1000","1000"};
	m = 9, n = 3;
	number = s.findMaxForm(strs7, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs8{"11","10","00","10", "00", "11", "10"};
	m = 3, n = 3;
	number = s.findMaxForm(strs8, m, n);
	cout << "max number: " << number << endl;

	vector<string> strs9{"00","10","00","10", "00", "11", "10"};
	m = 3, n = 3;
	number = s.findMaxForm(strs9, m, n);
	cout << "max number: " << number << endl;

	return 0;
}
