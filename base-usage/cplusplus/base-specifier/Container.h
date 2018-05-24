/*************************************************************************
	> File Name: Container.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月14日 星期一 10时54分53秒
 ************************************************************************/

#include <iostream>
#include <list>
#include "Vector.h"

#ifndef _SCZZQ_CONTAINER_H_
#define _SCZZQ_CONTAINER_H_

namespace sczzq{

class Container{
	public:
		virtual double& operator[](int) = 0;
		virtual int size() const = 0;
		virtual ~Container() {}
};

class Vector_container : public Container {
	private:
		Vector<double> v;
	public:
		Vector_container(int s) : v(s) { }
		~Vector_container() { }

		double& operator[](int i) { return v[i]; }
		int size() const { return v.size(); }
};

class List_container : public Container {
	private:
		std::list<double> ld;
	public:
		List_container() { }
		List_container(std::initializer_list<double> il) : ld{il} { }
		~List_container() { }
		double& operator[](int i);
		int size() const { return ld.size(); }
};

double& List_container::operator[](int i)
{
	for(auto& x : ld){
		if(i == 0) return x;
		--i;
	}
	throw std::out_of_range("List container");
}

};

#endif
