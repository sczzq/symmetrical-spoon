/*************************************************************************
	> File Name: 43_multipy_strings.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 03 May 2017 03:11:51 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string multipyStrings(string a, string b){
		string max, min;
		if(a.length() >= b.length()){
			max = a; min = b;
		} else {
			max = b; min = a;
		}

		if(min.length() <= 0)
			return {};

		string rmin = reverseEndian(min);
		string rmax = reverseEndian(max);
		generatorMTable();
		generatorATable();

		cout << min << '\n';
		cout << max << '\n';

		string res = oneMultipyString(rmin[0], rmax);;
		cout << res << "\n";
		for(int i=1; i<rmin.length(); i++){
			cout << "rmin[i]=" << rmin[i] << ": ";
			string s1 = oneMultipyString(rmin[i], rmax);;
			cout << s1 << "\n";
			string s2 = stringShift(i, s1);
			cout << s2 << "\n";
			res = stringAddString(res, s2);
			cout << res << "\n";
		}

		return reverseEndian(res);
	}

	// s is little-endian.
	// return value is little-endian.
	string stringShift(int len, string s){
		string res;
		for(int i=0; i<len; i++)
			res += '0';
		res += s;
		return res;
	}

	// a and b are little-endian string number.
	// return value is little-endian.
	string stringAddString(string a, string b){
		int reserve = 0;
		string sas, maxs, mins;
		if(a.length() >= b.length()){
			maxs = a; mins = b;
		} else {
			maxs = b; mins = a;
		}
		for(int i=0; i<mins.length(); i++){
			int icmax = maxs[i] - '0';
			int icmin = mins[i] - '0';
			// icmax in [0,9], icmin in [0,9].
			string res = atable[icmax][icmin];
			if(reserve){
				string rres = reverseEndian(res);
				res = atable[reserve][stoi(rres)];
			}
			if(res.length() == 2){
				reserve = res[1] - '0';
			} else {
				reserve = 0;
			}
			sas += res[0];
		}
		for(int i=mins.length(); i<maxs.length(); i++){
			int ic = maxs[i] - '0';
			string res;
			if(reserve){
				res = atable[reserve][ic];
			} else {
				res = atable[0][ic];
			}
			if(res.length() == 2){
				reserve = res[1] - '0';
			} else {
				reserve = 0;
			}
			sas += res[0];
		}
		if(reserve){
			char ccc = reserve + '0';
			sas += ccc;
		}

		return sas;
	}

	// s is little-endian
	// return value is little-endian
	string oneMultipyString(char c, string s){
		int reserve = 0;
		int ic = c - '0';
		if(ic == 0)
			return "0";
		string oms;
		for(int i=0; i<s.length(); i++){
			int is = s[i] - '0';
			string res = mtable[ic][is];
			if(reserve){
				//reserver in [0,9], res in [0,81].
				string rres = reverseEndian(res);
				res = atable[reserve][stoi(rres)];
			}
			if(res.length() == 2){
				reserve = res[1] - '0';
			} else {
				reserve = 0;
			}
			oms += res[0];
		}
		if(reserve){
			char ccc = '0' + reserve; 
			oms += ccc;
		}
		return oms;
	}

	void generatorMTable(){
		for(int i=0; i<10; i++){
			vector<string> col;
			for(int j=0; j<82; j++){
				string ssss = reverseEndian(to_string(i*j));
				col.push_back(ssss);
			}
			mtable.push_back(col);
		}
	}

	void generatorATable(){
		for(int i=0; i<10; i++){
			vector<string> col;
			for(int j=0; j<82; j++){
				string ssss = reverseEndian(to_string(i+j));
				col.push_back(ssss);
			}
			atable.push_back(col);
		}
	}

	string reverseEndian(string s){
		string rev;
		for(int i=s.length()-1; i>=0; i--)
			rev += s[i];
		return rev;
	}
private:
	vector<vector<string>> mtable;
	vector<vector<string>> atable;
};

int main()
{
	Solution s;
	string a{"123"};
	string b{"45"};

	cout << "\n" << s.multipyStrings(a, b) << "\n";

	a = {"9"};
	b = {"99"};
	cout << "\n" << s.multipyStrings(a, b) << "\n";
	a = {"0"};
	b = {"99"};
	cout << "\n" << s.multipyStrings(a, b) << "\n";
	a = {"123456789"};
	b = {"987654321"};
	cout << "\n" << s.multipyStrings(a, b) << "\n";
	a = {"12"};
	b = {"98"};
	cout << "\n" << s.multipyStrings(a, b) << "\n";
}

