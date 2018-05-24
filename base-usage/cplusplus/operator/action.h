/*************************************************************************
	> File Name: action.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 11:55:04 AM CST
 ************************************************************************/

#ifndef _ACTION_H_
#define _ACTION_H_

#include <iostream>
#include <utility>
using std::pair;

struct Action {
	int operator()(int);
	pair<int, int> operator()(int, int);
	double operator()(double);
};

#endif

