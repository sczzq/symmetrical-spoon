/*************************************************************************
	> File Name: test_static_local_variable.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 04 May 2017 09:59:50 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int foo2(int a){
	static int c = a;
	c = a;
	cout << "c=" << c << endl;
	return a;
}

int foo(int a)
{
	static int c = a++;
	cout << "c=" << c << endl;
	return a;
}

int h()
{
	foo(10);
	foo(20);

	foo2(10);
	foo2(20);
}

int main()
{
	h();
}
