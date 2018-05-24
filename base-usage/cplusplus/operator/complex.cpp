/*************************************************************************
	> File Name: complex.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 21 Apr 2018 12:27:31 PM CST
 ************************************************************************/

#include "complex.h"

namespace sczzq {

complex operator+(complex a, complex b)
{
	return a+=b;
}

complex operator-(complex a, complex b)
{
	return a-=b;
}

complex operator*(complex a, complex b)
{
	return a*=b;
}

complex operator/(complex a, complex b)
{
	return a/=b;
}

bool operator==(complex a, complex b){
	return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b){
	return !(a==b);
}

ostream& operator<<(ostream& os, const complex& a)
{
	os << a.real() << "," << a.imag();
	return os;
}

complex polar(double rho, double theta)
{
	return {rho, theta}; // just for implementation, not right.
}
complex conj(complex a)
{
	return a;
}
double abs(complex a)
{
	return a.real();
}
double arg(complex a)
{
	return a.real();
}
double norm(complex a)
{
	return a.real();
}
double real(complex a)
{
	return a.real();
}
double imag(complex a)
{
	return a.imag();
}
complex acos(complex a)
{
	return a;
}
complex asin(complex a)
{
	return a;
}
complex atan(complex a)
{
	return a;
}
complex actan(complex a)
{
	return a;
}


} // namespace sczzq.

