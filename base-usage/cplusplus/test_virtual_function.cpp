/*************************************************************************
	> File Name: test_virtual_function.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 05 May 2017 02:43:14 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base{
public:
	virtual void print(int a){
		cout << "in base print " << a << "\n";
	}
	void print2(int a){
		cout << "in base print2 " << a << "\n";
	}
};

class SubBase : public Base {
	void print(int a){
		cout << "in subbase print " << a << "\n";
	}

	void print2(int a){
		cout << "in subbase print2 " << a << "\n";
	}
};

int foo(Base& b)
{
	b.print(10);
	b.print2(20);
}

int f()
{
	Base b;
	SubBase sb;

	foo(b);
	foo(sb);
}

int main()
{
	f();
}

