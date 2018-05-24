/*************************************************************************
	> File Name: test_exception_ptr.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 09:49:53 PM CST
 ************************************************************************/

#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int hoo(){
	throw std::logic_error{"some logic error"};
}

int foo()
{
	std::exception_ptr ep;
	try{
		hoo();
	} catch(std::exception le) {
		ep = std::current_exception();
		cout << "exception caught, but continue...\n";
	}

	cout << "after get exception\n";

	try{
		std::rethrow_exception(ep);
	} catch (std::exception le){
		cout << "caught some exception: " << le.what() << "\n";
	}
}

int main()
{
	foo();
}
