/*************************************************************************
	> File Name: test_alian.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 03:07:51 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

using Pchar = char *;
using PF = int(*)(double );
//using PF2 = int()(double ); // wrong.

int foo(double db)
{
	cout << db << "\n";
}

int f()
{
	Pchar pc = "string";
	PF pf = foo;
	cout << pc << "\n";

	pf(2.0);
}

int main(){
	f();
}
