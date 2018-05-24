/*************************************************************************
	> File Name: test_vector_vector.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 03:52:55 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int f()
{
	vector<vector<int>> vvi;
	int size = 20;
	for(int i=0; i<size; i++)
		vvi.push_back(vector<int>(size));

	for(auto& vi : vvi)
		for(auto& x : vi)
			x = size;
	
	cout << vvi.size() << "\n";

	for(auto& vi : vvi){
		for(auto& x : vi)
			cout << x << " ";
		cout << '\n';
	}
}

int g()
{
	vector<vector<int>> vvi;
	for(int i=0; i<20; i++)
		vvi.push_back(vector<int>(20));

	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			vvi.at(i).at(j) = i+j;

	for(auto& vi : vvi){
		for(auto & x : vi)
			cout << x << " ";
		cout << '\n';
	}
}

int main()
{
//	f();
	g();
}
