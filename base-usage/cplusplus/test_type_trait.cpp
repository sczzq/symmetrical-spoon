/*************************************************************************
	> File Name: test_type_trait.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 10:05:47 PM CST
 ************************************************************************/

#include <iostream>
#include <type_traits>
using namespace std;

int foo()
{
	if(std::is_integral<int>())
		cout << "int is integral\n";

	if(std::is_integral<int>::value)
		cout << "int is integral\n";

	if(std::is_integral<char>::value)
		cout << "char is integral\n";
}

int main()
{
	foo();
}
