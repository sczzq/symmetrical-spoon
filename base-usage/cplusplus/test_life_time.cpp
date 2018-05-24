/*************************************************************************
	> File Name: test_life_time.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 05:56:24 PM CST
 ************************************************************************/

#include <iostream>
#include <vector> // vector
using namespace std;

class F{
public:
	F(): test{0} { cout << "0 default constructor\n" ; } // default constructor
	F(int t) : test{t} { cout << t << " parameter constructor\n"; } // using parameter to comstructor
	F(const F& f): test{f.test} { cout << test << " copy constructor\n" ; } // copy constructor
	F(F&& f): test{f.test} { f.test = 0; cout << test << " move constructor\n" ; } // move constructor

	int show() {return test; }

	~F() { cout << test << " deconstructor\n"; }

	F& operator=(const F& f) {cout << "copy operator\n"; test = f.test+1; return *this;} // copy operator
	F& operator=(F&& f) {cout << "move operator \n"; test = f.test+5; f.test = 0; return *this;} // move operator
private:
	int test;
};

int f()
{
	vector<F> vf;
	cout << "F f{10}: ";
	F f{10};
	cout << "vf.push_back(f): ";
	vf.push_back(f);
	cout << "vf.pop_back(): ";
	vf.pop_back();

	cout << "vf.push_back(f): ";
	vf.push_back(f);
	cout << "F& f2 = vf.at(0): ";
	F f2 = vf.at(0); // equel to F f2 { vf.at(0) } ;
	cout << "fs.show(): " << f2.show() << "\n";
	cout << "vf.erase(vf.begin()): ";
	vf.erase(vf.begin());
	cout << "fs.show(): " << f2.show() << "\n";

	cout << "vf.push_back(F{20}): ";
	vf.push_back(F{200});
	cout << "vf.pop_back(): ";
	vf.pop_back();

	cout << "f2 = f: ";
	f2 = f;

	cout << "F f3 = std::move(f): ";
	F f3 = std::move(f);

	cout << "f3 = f: ";
	f3 = std::move(f);

	F ff{2000};
	vf.push_back(ff);
	F ff2 { vf.at(0) };
	vf.erase(vf.begin());
	F ff3 {std::move(ff)};
	ff3 = std::move(ff2);

//	ff3{200}; error

}

int main()
{
	f();
}
