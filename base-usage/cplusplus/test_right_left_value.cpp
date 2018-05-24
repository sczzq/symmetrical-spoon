/*************************************************************************
	> File Name: test_right_left_value.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 02:42:14 PM CST
 ************************************************************************/

#include <iostream>
#include <vector> // vector
using namespace std;

// move value of vi out.
int f(vector<int>& vi)
{
	vector<int> v2 = std::move(vi);
	for(auto x : v2)
		cout << x << " ";
	cout << "\n";
}

int h()
{
	vector<int> v(10, 1);
	f(v);

	cout << v.size() << "\n"; // is 0
	for(auto x : v)
		cout << x << ' ';  // is null
	cout << '\n';
}

int main()
{
	h();
}
