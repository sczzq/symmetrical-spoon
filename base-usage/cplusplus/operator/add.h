/*************************************************************************
	> File Name: add.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 12:01:38 PM CST
 ************************************************************************/

#ifndef _ADD_H_
#define _ADD_H_

#include <iostream>
#include "complex.h"

using sczzq::complex;

class Add{
	complex val;
public:
	Add(complex c):val{c} { }
	Add(double r, double i):val{r, i} { }

	void operator()(complex& c) const { c+=val; }
};

#endif

