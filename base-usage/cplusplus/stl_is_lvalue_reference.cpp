/*************************************************************************
	> File Name: stl_is_lvalue_reference.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月15日 星期二 16时52分44秒
 ************************************************************************/

#include <iostream>

#include <iostream>
#include <type_traits>
 
class A {};
 
int main() 
{
	std::cout << std::boolalpha;
	std::cout << std::is_lvalue_reference<A>::value << '\n';
	std::cout << std::is_lvalue_reference<A&>::value << '\n';
	std::cout << std::is_lvalue_reference<A&&>::value << '\n';
	std::cout << std::is_lvalue_reference<int>::value << '\n';
	std::cout << std::is_lvalue_reference<int&>::value << '\n';
	std::cout << std::is_lvalue_reference<int&&>::value << '\n';
}
