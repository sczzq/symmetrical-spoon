/*************************************************************************
	> File Name: pex58.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 01:11:08 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> vs {"Kant", "Plato", "Aristotle", "Kierkegard", "Hume" };

	for(string s : vs)
		cout << s << ", ";
	cout << endl;

	sort(vs.begin(), vs.end());

	for(string s : vs)
		cout << s << ", ";
	cout << endl;

	return 0;
}
