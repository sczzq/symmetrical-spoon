/*************************************************************************
	> File Name: test_constructor_sequence.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 06:53:04 PM CST
 ************************************************************************/

#include <iostream>
#include <array>
using namespace std;

// first construct f0, is the member of F1,
// then  construct f1, is the member of F2,
// then  construct f2, is the object of class F2.
//

class B0{
public:
	B0(int a) { cout << "constructor B0\n"; }
	~B0() { cout << "deconstructor B0\n"; }
};

class B1{
public:
	B1(int a) { cout << "constructor B1\n"; }
	~B1() { cout << "deconstructor B1\n"; }
};

class B2{
public:
	B2() { cout << "constructor B2\n"; }
	~B2() { cout << "deconstructor B2\n"; }
};

class B3{
public:
	B3() { cout << "constructor B3\n"; }
	~B3() { cout << "deconstructor B3\n"; }
};

class F0 : public B0
{
public:
	F0(): B0{1} { cout << "constructor F0\n"; }
	~F0() { cout << "deconstructor F0\n"; }
};

class F1 : public B1
{
	array<int, 1> arr;
	F0 f0;
public:
	F1(int a): B1{1}, arr{a} { cout << "using array to constructor F1\n";}
	~F1() { cout << "deconstructor F1\n"; }
};

template <typename T>
class F2 : public B2{
	T t;
public:
	F2(int a): t{a} { cout << "using typename to constructor F2\n"; }
	~F2() { cout << "deconstructor F2\n"; }
};

class F3 : public B3{
	F1 f1{2};
public:
	F3() { cout << "constructor F3\n"; }
	~F3() { cout << "deconstructor F3\n"; }
};

int foo()
{
	cout << "a big booooo\n";
	F2<F1> sf{10};
	cout << "\nanother big boooo\n";
	F3 f3;
}

int main()
{
	foo();
}

