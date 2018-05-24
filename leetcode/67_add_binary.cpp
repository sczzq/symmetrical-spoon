/*************************************************************************
	> File Name: 67_add_binary.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 03 May 2017 02:43:42 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
	string addBinary(string a, string b){
		// assume a, b is big-endian
		// then get its little-endian string
		string la = reverseEndian(a);
		string lb = reverseEndian(b);
		string lsum;
		int reserver = 0;
		int minuj = min(la.length(), lb.length());
		int maxuj = max(la.length(), lb.length());
		for(int i=0; i<minuj; i++){
			if( reserver ){
				if(la[i] == '1' && lb[i] == '1'){
					lsum += "1";
					reserver = 1;
				}
				else if(la[i] == '0' && lb[i] == '0'){
					lsum += "1";
					reserver = 0;
				} else {
					lsum += "0";
					reserver = 1;
				}
			} else {
				if(la[i] == '1' && lb[i] == '1'){
					lsum += "0";
					reserver = 1;
				} else if(la[i] == '0' && lb[i] == '0'){
					lsum += "0";
				} else {
					lsum += "1";
				}
			}
		}
		string smax;
		if(maxuj == la.length()){
			smax = la;
		} else smax = lb;
		for(int i=minuj; i < maxuj; i++){
			if(reserver){
				if(smax[i] == '0'){
					lsum += '1';
					reserver = 0;
				} else {
					lsum += '0';
					reserver = 1;
				}
			} else {
				lsum += smax[i];
			}
		}
		if(reserver)
			lsum += '1';
		return reverseEndian(lsum);
	}

	string reverseEndian(string s)
	{
		string r;
		for(int i=s.length()-1; i>=0; i--){
			char c = s[i];
			r += c;
		}
		return r;
	}
};

int main()
{
	Solution s;
	string a = "11";
	string b = "1";

	cout << s.addBinary(a, b) << "\n";

	string b2 = "10001";
	cout << s.addBinary(a, b2) << "\n";
}
