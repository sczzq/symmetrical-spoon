/*************************************************************************
	> File Name: map.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 01 May 2018 10:47:24 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <memory>
//#include <utilities>

using std::cout;
using std::endl;
using std::map;
using std::unique_ptr;

class Foo {
	int num;
	public:
		Foo(int i): num{i}
			{ cout << "Foo " << num << "in\n"; }
		~Foo() { cout << "Foo " << num << " out\n"; }
};

int main()
{
	map<int, unique_ptr<Foo>> mf;

//	unique_ptr<Foo> f1 (new Foo(1));
	unique_ptr<Foo> f2 (new Foo(2));
	mf.insert(std::pair<int, unique_ptr<Foo>>(1, unique_ptr<Foo>(new Foo(1))));
	mf.insert(std::pair<int, unique_ptr<Foo>>(2, std::move(f2)));

	mf.erase(mf.begin());

	cout << mf.size() << endl;
}
