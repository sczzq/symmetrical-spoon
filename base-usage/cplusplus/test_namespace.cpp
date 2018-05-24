/*************************************************************************
	> File Name: test_namespace.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 28 Apr 2017 10:33:51 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Estd{
	using namespace std;

	template <class C>
	void sort(C& c)
	{
		sort(c.begin(), c.end());
	}

	template < class C, class Pred>
	void sort(C& c, Pred p)
	{
		sort(c.begin(), c.end(), p);
	}
};

template <typename T>
class Less_than{
	const T val;
public:
	Less_than(T v): val{v} { }
	bool operator()(T v){ return val < v; }
};

template <typename T>
void print(T& t){
	for(auto& x : t)
		cout << x << ";";
	cout << endl;
}

int main()
{
	vector<int> vi { 5,4,3,2,6,7};
	print(vi);
	Estd::sort(vi);
	print(vi);
}
