/*************************************************************************
	> File Name: test_thread.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 28 Apr 2017 11:25:00 AM CST
 ************************************************************************/

#include <iostream>
#include <thread>
#include <vector>

/*
 * there are more infomation to see test_concurrent.cpp
 */

using namespace std;

void f2(vector<int> v) { 
	cout << "in function f2\n";
	for(auto x : v)
		cout << x << " ";
	cout << endl;
}

struct F2{
	vector<int> v;
	F2(vector<int>& vv): v{vv} { }
	void operator()(){
		cout << "int class F2\n";
		for(auto x : v)
			cout << x << " ";
		cout << endl;
	}
};

int m2()
{
	vector<int> v;
	for(int i=0; i<10; i++)
		v.push_back(i);
	thread t1 {f2, v};
	thread t2 {F2{v}};

	t1.join();
	t2.join();
}

int main()
{
	m2();
}
