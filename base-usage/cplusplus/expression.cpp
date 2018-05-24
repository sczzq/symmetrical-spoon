/*************************************************************************
	> File Name: expression.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 15 Apr 2018 04:03:59 PM CST
 ************************************************************************/

#include <iostream>

int main()
{
	int a = 16;
	int b = 28;

	int c = a | b;
	int d = static_cast<int>(a) & static_cast<int>(b);

	std::cout << c << ' ' << d << "\n";
}
