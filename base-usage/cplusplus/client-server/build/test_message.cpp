/*************************************************************************
	> File Name: test_message.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 12 May 2017 10:29:36 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

#include "message.hpp"

using namespace std;
using namespace Anomynous;

int foo()
{
	Message msg{1, 2, "hello"};
	msg.deal();

	cout << msg.toString() << endl;

	cout << "sizeof(Message)=" << sizeof(Message) << endl;
	cout << "sizeof(msg)=" << sizeof(msg) << endl;

	Message* pmsg = new Message(1, 2, "hello world");
	cout << pmsg->toString() << endl;
	delete pmsg;
}

int main()
{
	foo();
}
