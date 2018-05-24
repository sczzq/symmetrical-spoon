/*************************************************************************
	> File Name: test_recursion.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 16 May 2017 10:23:18 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int foo(int a)
{
	if(a == 0)
		return 0;
	return a + foo(a-1);
}

int main()
{
	cout << foo(100000) << endl;
}
