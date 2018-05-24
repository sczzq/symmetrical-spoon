/*************************************************************************
	> File Name: test_exception_2.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 09:32:15 PM CST
 ************************************************************************/

#include <iostream>
#include <exception>
using namespace std;

void fun2(){
	cout << "unexpection throw handler\n";
	throw;
}

void fun() throw (int, std::bad_exception)
{
	throw 'x';
}

int f00()
{
	std::set_unexpected(fun2);
	try{
		fun();
	} catch (int){
		cout << "caught int\n";
	} catch (std::bad_exception& be){
		cout << "bad_exception " << be.what() << "\n";
	} catch (...) {
		cout << "caught other exception\n";
	}

}

int main()
{
	f00();
}
