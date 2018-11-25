/*************************************************************************
    > File Name: painter.h
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年11月25日 星期日 23时08分24秒
 ************************************************************************/

#pragma once

#include<iostream>
using namespace std;
#include "turtle.h"
class Painter {
public:
	Painter(Turtle *turtle)
	  : m_turtle(turtle){
	};

	bool DrawCircle(int i, int j, int k){
		cout << i << "," << j << "," << k << endl;
		m_turtle->PenDown();
		return true;
	};

	Turtle *m_turtle;
};

