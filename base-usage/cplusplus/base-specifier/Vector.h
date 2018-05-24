/*************************************************************************
	> File Name: Vector.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月13日 星期日 23时02分28秒
 ************************************************************************/

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>

#ifndef _SCZZQ_VECTOR_H_
#define _SCZZQ_VECTOR_H_
/*
 * Note
 * 使用new/delete进行对象的存储空间分配,例子 见 行27, 32
 * 构造函数请求资源,析构函数释放资源. 
 *
 * 类内成员函数中的类的对象可以访问类的私有变量.
 *
 * 在作用域Vector{ } 中,引用Vector 名字时不需要进行模板实例化
 * 此作用域内的 Vector 名字默认使用类头的限定词.
 *
 */

namespace sczzq{
	template<typename T = double>
	class Vector{
		private:
			T * elem;
			size_t sz;
		public:
			Vector(size_t s) : elem { new T[s]}, sz{s} // 构造函数.
			{
				for(int i = 0; i != s; ++i) elem[i] = 0;
			}

			Vector(std::initializer_list<T> lst)  // 构造函数.
				:elem { new T[lst.size()]},
				 sz { lst.size() }
			{
				std::copy(lst.begin(), lst.end(), elem);
			}

			~Vector() {  // 析构函数.
				if(elem)
					delete[] elem;
			}

			Vector(const Vector& a)  // 拷贝构造函数.
				:elem{new T[a.sz]},
				 sz{a.sz}
			{
				for(int i = 0; i < sz; ++i){
					elem[i] = a.elem[i];
				}
			}
			Vector& operator=(const Vector& a){ // 拷贝赋值运算符.
				T* p = new T[a.sz];
				for(int i = 0; i < a.sz; i++){
					p[i] = a.elem[i];
				}
				delete[] elem;
				elem = p;
				sz = a.sz;
				return *this;
			}

			Vector(Vector&& a) // 移动构造函数
				:elem{a.elem},  // get the element from a
				 sz{a.sz}
			{
				a.elem = nullptr; // set null to a.
				a.sz = 0;
			}

			Vector& operator=(Vector&& a) // 移动赋值运算符
			{
				delete[] elem;

				elem = a.elem;
				sz = a.sz;
				a.elem = nullptr;
				a.sz = 0;
			}

			T & operator[](int i)
			{
				if(i < 0 || i >= sz)
					throw std::out_of_range("out of max size.");
				return elem[i];
			}

			int size() const
			{
				return sz;
			}

			void push_back(T b)
			{
				b = b;
			}

			T* begin(){
				return elem;
			}
			T* end(){
				return elem+sz;
			}
	};

};

#endif

