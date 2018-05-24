/*************************************************************************
	> File Name: action.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 11:56:27 AM CST
 ************************************************************************/

#include <iostream>
#include "action.h"

int Action::operator()(int a)
{
	std::cout << a << std::endl;
	return 2*a;
}

std::pair<int, int> Action::operator()(int a, int b)
{
	std::cout << a << ", " << b << "\n";
	return pair<int, int>{a, b};
}

double Action::operator()(double d)
{
	std::cout << d << std::endl;
	return 2*d;
}


