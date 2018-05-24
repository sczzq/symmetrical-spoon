/*************************************************************************
	> File Name: complex.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 12:27:37 PM CST
 ************************************************************************/
#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

using std::ostream;

namespace sczzq{

class complex {
	double re, im;
public:
	constexpr complex(double r=0, double i=0) : re{r}, im{i} { }

	constexpr double real() const {return re;}
	constexpr double imag() const {return im;}

	void real(double r) { re = r; }
	void imag(double i) { im = i; }

	complex& operator+=(complex a){
		re += a.re;
		im += a.im;
		return *this;
	}

	complex& operator-=(complex a){
		re -= a.re;
		im -= a.im;
		return *this;
	}

	complex& operator*=(complex a){
		re *= a.re;
		im *= a.im;
		return *this;
	}

	complex& operator/=(complex a){
		re /= a.re;
		im /= a.im;
		return *this;
	}

};

complex operator+(complex a, complex b);
complex operator-(complex a, complex b);
complex operator*(complex a, complex b);
complex operator/(complex a, complex b);

bool operator==(complex a, complex b);
bool operator!=(complex a, complex b);

complex polar(double rho, double theta);
complex conj(complex);

double abs(complex);
double arg(complex);
double norm(complex);

double real(complex);
double imag(complex);

complex acos(complex);
complex asin(complex);
complex atan(complex);
complex actan(complex);

ostream& operator<<(ostream&, const complex&);

} // namespace sczzq

#endif

