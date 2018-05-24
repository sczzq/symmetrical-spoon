/*************************************************************************
	> File Name: pex72.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 06:31:14 PM CST
 ************************************************************************/

#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	char c = 'a';
	unsigned char uc = 'b';

	if(typeid(c) == typeid(char))
		cout << "c: " << c << " is signed" ;
	else
		cout << "c: " << c << " is unsigned" ;
	cout << endl;

	if(typeid(uc) == typeid(char))
		cout << "uc: " << uc << " is signed" ;
	else
		cout << "uc: " << uc << " is unsigned" ;
	cout << endl;

	return 0;
}

