/*************************************************************************
    > File Name: header.h
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年08月19日 星期日 16时37分10秒
 ************************************************************************/

#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
#include<vector>
using namespace std;

void showVector(vector<int> &v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}

#endif

