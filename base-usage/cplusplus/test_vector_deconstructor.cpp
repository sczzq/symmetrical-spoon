/*************************************************************************
	> File Name: test_vector_deconstructor.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 07:29:41 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class F{
public:
	F() { cout << "default construct F\n"; }

	F(F& f) { cout << "copy construct F\n"; }
	F(F&& f) { cout << "move construct F\n"; }

	~F() { cout << "deconstruct F\n"; }

};

F ffff;

int h00()
{
	static F f;
}

int foo()
{
	vector<F> vf;

	cout << "---------\n";
	vf.push_back(F{});  // first construct one temp object of F,
						// then move the object to parameter of vf.push_back,
						// and then deconstruct temp object F.
	cout << "---------\n";

	{
		cout << "hello\n";
		F f = vf.at(0);
		cout << "world\n";
	}
	cout << "oooh, do four h00()\n";
	h00();
	h00();
	h00();
	h00();
	cout << "end of four h00()\n";
}

int main()
{
	foo();
};
