/*************************************************************************
	> File Name: test_generator.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 27 Apr 2017 10:17:53 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class mcomplex{
	double re, im;
public:
	mcomplex(double r, double i): re{r}, im{i} { }
	mcomplex(double r): re{r}{ }
	mcomplex(): re{0.0}, im{0.0} { }

	mcomplex& operator=(const mcomplex& c){ re = c.re; im = c.im; return *this; }

	double real() const { return re;}
	double real(double r) { re = r;}
	double image() const { return im;}
	double image(double i) { im = i;}

	mcomplex& operator+=(mcomplex z) { re += z.re; im += z.im; return *this; }
	mcomplex& operator-=(mcomplex z) { re -= z.re; im -= z.im; return *this; }
	mcomplex& operator*=(mcomplex z) { re *= z.re; im *= z.im; return *this; }
	mcomplex& operator/=(mcomplex z) { re /= z.re; im /= z.im; return *this; }
};

mcomplex operator+(mcomplex a, mcomplex b) { return a+=b;}
mcomplex operator-(mcomplex a, mcomplex b) { return a-=b;}
mcomplex operator-(mcomplex a) { return {-a.real(), -a.image()};}
mcomplex operator*(mcomplex a, mcomplex b) { return a*=b;}
mcomplex operator/(mcomplex a, mcomplex b) { return a/=b;}

bool operator==(mcomplex a, mcomplex b) { return a.real()==b.real() && a.image()==b.image(); }
bool operator!=(mcomplex a, mcomplex b) { return !(a==b); }

ostream& operator<<(ostream& os, mcomplex z)
{
	os << "{" << z.real() << "," << z.image() << "}" ;
}

istream& operator>>(istream& is, mcomplex& z)
{
	double re, im;
	is >> re >> im;
	z = {re, im};
	return is;
}

int main()
{
	mcomplex a, b;

	a = {1.0, 2.0};
	cout << a << '\n';

	cin >> b;
	cout << b << '\n';

	mcomplex c = a/b;
	cout << c << '\n';
	c = a+b;
	cout << c << '\n';
	c = a-b;
	cout << c << '\n';
	c = a*b;
	cout << c << '\n';
}


