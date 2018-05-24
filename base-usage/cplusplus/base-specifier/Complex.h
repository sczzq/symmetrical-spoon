/*************************************************************************
	> File Name: Complex.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月14日 星期一 09时46分27秒
 ************************************************************************/

/*
 * Note:
 * 类内的成员函数,类对象,都可以访问类内成员. 例子见 行27.
 * 定义在类内部的函数默认是内联的.
 * 无须实参就可以调用的构造函数称为默认构造函数.
 * 以传值的方式传递实参实际上是把一份副本传递给函数.
 */

#include <iostream>

#ifndef SCZZQ_COMPLEX_H_
#define SCZZQ_COMPLEX_H_

namespace sczzq{
class Complex {
	private:
		double re, im;
	public:
		Complex(double r, double i) : re{r}, im{i} {}
		Complex(double r): re{r}, im{0} {}
		Complex() : re{0}, im{0} {}

		double real() const {return re;}
		void real(double d){ re = d; }
		double imag() const {return im;}
		void imag(double d) { im = d; }

		Complex& operator+=(Complex z) // 类对象z 出现在类内,可以访问类内的私有成员.
		{
			re+=z.re; im+=z.im; return *this;
		}

		Complex& operator-=(Complex z) { re-=z.re; im-=z.im; return *this;}
		Complex& operator*=(Complex z) { re*=z.re; im*=z.im; return *this;}
		Complex& operator/=(Complex z) { re/=z.re; im/=z.im; return *this; }
};

Complex operator+(Complex a, Complex b){ return a+=b; }
Complex operator-(Complex a, Complex b){ return a-=b; }
Complex operator-(Complex a){ return {-a.real(), -a.imag()}; }
Complex operator*(Complex a, Complex b){ return a*=b; }
Complex operator/(Complex a, Complex b){ return a/=b; }

bool operator==(Complex a, Complex b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(Complex a, Complex b)
{
	return !(a==b);
}

std::ostream& operator<<(std::ostream& cont, Complex z)
{
	cont << "{" << z.real() << "," << z.imag() << "}";
	return cont;
}

};

#endif

