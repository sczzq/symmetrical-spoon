/*************************************************************************
	> File Name: assoc.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 10:58:04 AM CST
 ************************************************************************/

#include <iostream>
#include "assoc.h"

using std::cin;
using std::cout;
using std::cerr;

int& Assoc::operator[](const string& s)
{
	for(auto& x : vec){
		if(s == x.first) return x.second;
	}

	vec.push_back({s, 0});

	return vec.back().second;
}

