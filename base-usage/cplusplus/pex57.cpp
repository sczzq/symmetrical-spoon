/*************************************************************************
	> File Name: pex57.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 01:06:12 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> a{5, 9, -1, 200, 0};
	for(int i : a)
		cout << i << ", ";
	cout << endl;

	sort(a.begin(), a.end());

	for(int i : a)
		cout << i << ", ";
	cout << endl;

	return 0;
}
