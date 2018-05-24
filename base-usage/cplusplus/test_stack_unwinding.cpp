/*************************************************************************
	> File Name: test_stack_unwinding.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 08:04:51 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class M{
public:
	M(int a): n{a} { cout << n << " coustruct M\n"; }
	~M() { cout << n << " decoustruct M\n"; }
private:
	int n;
};

class Myerror{ 
public:
	Myerror(int a) { cout << "error in " << a << "\n";}
	~Myerror() { cout << "deconstruct myerror\n"; }
	Myerror(const Myerror& err) {cout << "copy construct myerror\n"; }
	Myerror(Myerror&& err) {cout << "move construct myerror\n"; }
};

int f(); 
int g();
int h();

int f(){
	M m1{1};
	try{
		M m2{2};
		g();
	} catch (Myerror) { // until here, copy construct Myerror object.
		cout << "here is end\n";
	}
} // 1 deconstruct represent after "here is end\n".

int g()
{
	M m3{3};
	{
		M m4{4};
		h();
	}
}

int h()
{
	M m5{5};
	{
		throw Myerror{5};
	}
	M m6{6};
}

/*
 * expect output is
 * 1 coustruct M
 * 2 coustruct M
 * 3 coustruct M
 * 4 coustruct M
 * 5 coustruct M
 * error in 5
 * 5 decoustruct M
 * 4 decoustruct M
 * 3 decoustruct M
 * 2 decoustruct M
 * copy construct myerror
 * here is end
 * deconstruct myerror
 * deconstruct myerror
 * 1 decoustruct M
 *
 */
int stack_unwinding_test()
{
	f();
}

int main()
{
	stack_unwinding_test();
}

