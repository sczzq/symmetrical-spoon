/*************************************************************************
	> File Name: functionTemplateAndObject.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 27 Apr 2017 02:38:32 PM CST
 ************************************************************************/

#include <iostream>
#include <vector> // vector
#include <string> // string
using namespace std;

template<typename T>
class Less_than{
	const T val;
public:
	Less_than(const T& v): val{v} { }
	bool operator()(const T& v){ return v < val; }
};

template<typename T, typename P>
int count(T& vec, P pred)
{
	int cnt = 0;
	for(auto& x : vec)
		if(pred(x))
			++cnt;
	return cnt;
}

void f(const vector<int>& vi, const vector<string>& vs, const int x, const string& str)
{
	cout << "less than " << str << ", count is " << count(vs, Less_than<string>{str}) << endl;
	cout << "less than " << x << ", count is " << count(vi, Less_than<int>{x}) << endl;
}

/*
 * lambda cannot use here, g++ 3.8.5, -std=c++11
void g(const vector<int>& vi, const vector<string>& vs, const int x, const string& str)
{
	cout << "less than " << str << ", count is " << count(vs, [&x](string a){return a < x; } ) << endl;
	cout << "less than " << x << ", count is " << count(vi, [&x](int a){return a < x;} ) << endl;
}
*/

int main()
{
	vector<int> vi { 3,4,5,1,2,3};
	vector<string> vs{"hello", "world", "china", "yingyang"};

	int x = 2;
	string str { "print" };

	cout << "x = " << x << ", vi is ";
	for(auto& i : vi)
		cout << i << ", ";
	cout << endl;

	cout << "string = " << str << ", vs is ";
	for(auto& s : vs)
		cout << s << ", ";
	cout << endl;

	f(vi, vs, x, str);
}
