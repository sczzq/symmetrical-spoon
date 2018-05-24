/*************************************************************************
	> File Name: test_function_point.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 05 May 2017 01:01:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void* x(int a){
	cout << a << '\n';
	return NULL;
}

int f()
{
	void* (*foo)(int);
	foo = x;
	foo(1);
}

int main()
{
	f();
}
