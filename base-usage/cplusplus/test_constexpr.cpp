/*************************************************************************
	> File Name: test_constexpr.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 26 Apr 2017 09:12:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n = 5;
	const auto a = 10;
	int m[n+1];
	int mm[a+1];
	int mmm[n][n];
	int mmmm[a][n];
	int mmmmm[a*a*a+n][n*n*n+a];

	for(int i=0; i<n+1; i++)
		m[i] = i;

	for(int i=0; i<n+1; i++)
		cout << m[i] << ",";
	cout << endl;

	for(int i=0; i<a+1; i++)
		mm[i] = i;
	for(int i=0; i<a+1; i++)
		cout << mm[i] << ",";
	cout << endl;

	return 0;
}
