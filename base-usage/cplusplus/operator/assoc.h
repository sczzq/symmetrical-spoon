/*************************************************************************
	> File Name: assoc.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 11:49:01 AM CST
 ************************************************************************/
#ifndef ASSOC_H_
#define ASSOC_H_

#include <string>
#include <utility>
#include <vector>

using std::string;
using std::pair;
using std::vector;

struct no_element { };

struct Assoc {
	vector<pair<string, int>> vec;

	const int& operator[] (const string&) const;
	int& operator[](const string&);
};

#endif
