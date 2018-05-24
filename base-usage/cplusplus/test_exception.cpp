/*************************************************************************
	> File Name: test_exception.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 01 May 2017 05:21:30 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int foo(int a)
{
	if(a < 0)
		throw 2;
	else
		cout << a << endl;

	return 0;
}

int h()
{
	try{
		foo(1);
	} catch (...) {
		cout << "exception\n";
	}

	try{
		foo(-1);
	} catch (...){
		cout << "exception\n";
	}
}

int foo2(int a)
{
	if(a > 0){
		vector<int> v(10);
		cout << v.at(200);
	} else {
		vector<int> v(10);
		cout << v.at(-10);
	}
}

int h2()
{
	try{
		foo2(2);
	} catch (std::exception & e) {
		cout << "exception " << e.what() << "\n";
	}
	try{
		foo2(-2);
	} catch (...) {
		cout << "exception\n";
	}
}

int h3()
{
	foo2(20);
}

int main()
{
//	h();
	h2();
//	h3();
}
