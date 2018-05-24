/*************************************************************************
	> File Name: terminater.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 07 Apr 2018 03:42:11 PM CST
 ************************************************************************/

#include <iostream>
#include <exception>
#include <stdexcept>

/*
 * 构造顺序,A, B
 * 也即是,先构造成员变量,再构造自身
 *
 * 当其中一个步骤抛出异常时,
 * 则跳出构造过程,也即是,没有完成构造
 *
 * 所以,捕获到的异常是 std::logic_error("A")
 * 打印的内容的 A.
 */
class A{
public:
	A() { throw std::logic_error("A");}
	~A() { }
};

class B {
	A a;
public:
	B() { throw std::out_of_range("B");}
	~B() { }
};

int func()
{
	B b;
}

int main(){
	try{
		func();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
