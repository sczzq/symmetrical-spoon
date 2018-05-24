/*************************************************************************
	> File Name: functionObject.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 27 Apr 2017 02:19:52 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
class Less_than{
	const T val;
public:
	Less_than(const T& v):val{v} { } // here can use val(v) or val{v}
	bool operator()(const T& v) const{ return v < val; }
};

int main()
{
	Less_than<int> lti {1};

	cout << lti(4) << endl;

	cout << lti(-1) << endl;

	Less_than<string> lts {"thank"};
	cout << lts("hello") << endl;
}


