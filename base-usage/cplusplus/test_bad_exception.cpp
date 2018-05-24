/*************************************************************************
	> File Name: test_bad_exception.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 09:44:35 PM CST
 ************************************************************************/

#include <iostream>
#include <exception>
using namespace std;

void myunexpection()
{
	cout << "unexpection exception\n";
	throw;
}

void myfunction() throw (int, std::bad_exception)
{
	throw 'x';
}

int foo()
{
	std::set_unexpected(myunexpection);
	try{
		myfunction();
	} catch (int) { cout << "caught int exception\n";
	} catch (std::bad_exception be) { cout << "caught std::bad_exception " << be.what() << "\n";
	} catch (...) { cout << "caught other exception\n"; }
}

int main()
{
	foo();
}

