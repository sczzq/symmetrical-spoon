/*************************************************************************
	> File Name: Ptr.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 02:45:34 PM CST
 ************************************************************************/

#ifndef _PTR_H_
#define _PTR_H_

template<typename T>
class Ptr{
	Y* p;
public:
	Y* operator->() { return p; }
	Y& operator*() { return *p; }
	Y& operator[](int i) { return p[i]; }
};

#endif

