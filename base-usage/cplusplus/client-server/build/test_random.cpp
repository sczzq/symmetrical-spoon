/*************************************************************************
	> File Name: test_random.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 13 May 2017 12:01:55 PM CST
 ************************************************************************/

#include <iostream>
#include "random.hpp"
using namespace std;
using namespace Anomynous;

int foo(int t)
{
	while( t > 0){
		cout << RandomUint64_t() << endl;
		t--;
	}
}

int f()
{
	foo(2);
	foo(2);
	foo(2);
}

int main()
{
	f();
}
