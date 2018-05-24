/*************************************************************************
	> File Name: test4.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 13 Aug 2017 06:58:43 PM CST
 ************************************************************************/

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
using namespace std;

int main()
{
	log4cpp::PatternLayout *pLayout1 = new log4cpp::PatternLayout();
	pLayout1->setConversionPattern("%d : %p %c%x: %m%n");

	log4cpp::PatternLayout *pLayout2 = new log4cpp::PatternLayout();
	pLayout2->setConversionPattern("%d: %p%c%x: %m%n");

	log4cpp::Appender *fileAppender = new log4cpp::FileAppender("fileAppender", "test4.log");
	fileAppender->setLayout(pLayout1);

	log4cpp::RollingFileAppender *rollingAppender = new log4cpp::RollingFileAppender("rollingAppender", "roll_test4.log", 5*1024, 1);
	rollingAppender->setLayout(pLayout2);

	log4cpp::Category &root = log4cpp::Category::getRoot().getInstance("rootname");
	root.addAppender(fileAppender);
	root.addAppender(rollingAppender);
	root.setPriority(log4cpp::Priority::ERROR);
	for(int i=0; i<1000; i++){
		string strerr;
		ostringstream oss;
		oss << i << ":RootError Message!";
		strerr = oss.str();
		root.info(strerr);
	}
	log4cpp::Category::shutdown();

	return 0;
}
