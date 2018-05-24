/*************************************************************************
	> File Name: test1.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 13 Aug 2017 06:22:00 PM CST
 ************************************************************************/

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

using namespace std;

int main()
{
	log4cpp::OstreamAppender *osAppender = new log4cpp::OstreamAppender("osAppender", &cout);
	osAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category &root = log4cpp::Category::getRoot();
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);
	root.error("log4cpp in a error message");
	root.warn("log4cpp in a warning message");
	log4cpp::Category::shutdown();
	return 0;
}
