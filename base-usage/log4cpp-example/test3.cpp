/*************************************************************************
	> File Name: test3.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 13 Aug 2017 06:48:05 PM CST
 ************************************************************************/

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/StringQueueAppender.hh>
using namespace std;

int main()
{
	log4cpp::StringQueueAppender *strQAppender = new log4cpp::StringQueueAppender("strQAppender");
	strQAppender->setLayout(new log4cpp::BasicLayout);

	log4cpp::Category &root = log4cpp::Category::getRoot();
	root.addAppender(strQAppender);
	root.setPriority(log4cpp::Priority::DEBUG);
	root.error("Hello log4cpp in a error message");
	root.warn("Hello log4cpp in a warn message");
	cout << "get message from memory queue!" << endl;
	cout << "------------------------------" << endl;

	queue<string> myStrQ = strQAppender->getQueue();
	while(!myStrQ.empty()){
		cout << myStrQ.front();
		myStrQ.pop();
	}
	log4cpp::Category::shutdown();

	return 0;
}
