/*************************************************************************
	> File Name: test_type_traits.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 10:12:02 PM CST
 ************************************************************************/

#include <iostream>
#include <type_traits>
using namespace std;

template <unsigned n>
struct factorial : integral_constant< int, n*factorial<n-1>::value> { };

template <>
struct factorial<0> : integral_constant<int, 1> { };

int compile_time_constant()
{
	cout << factorial<5>::value << "\n";
}

int foo(int a)
{
	decltype(a) b;
	cout << b << "\n";
}

int main()
{
	compile_time_constant();
	foo(1);
}
