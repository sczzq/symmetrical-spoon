/*************************************************************************
	> File Name: main.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 11:24:53 AM CST
 ************************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
#include "assoc.h"
#include "action.h"
#include "add.h"

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::list;

void test_add()
{
	vector<complex> vc(5, {1, 2});
	list<complex> lc(5, {3, 4});

	for(auto x : vc)
		cout << x << endl;
	for(auto x : lc)
		cout << x << endl;

	for_each(vc.begin(), vc.end(), Add{1,1});
	for_each(lc.begin(), lc.end(), Add{2,2});

	cout << "----------------" << endl;

	for(auto x : vc)
		cout << x << endl;
	for(auto x : lc)
		cout << x << endl;

}

void test_action()
{
	Action act;
	int a = act(2);
	pair<int, int> pa = act(2, 2);
	double d = act(2.3);

	std::cout << a << "," << pa.first << "-" << pa.second << "," << d << std::endl;
}

void test_assoc()
{
	try{
	Assoc values;
	string buf;
	while(cin>>buf) ++values[buf];
	for(auto x : values.vec) {
		cout << '{' << x.first << ',' << x.second << "}\n";
	}
	} catch (...) {
		cerr << "error\n";
	}
}

int main()
{
//	test_action();
//	test_assoc();
	test_add();
}
