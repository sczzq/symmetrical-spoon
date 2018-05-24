/*************************************************************************
	> File Name: test2.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 13 Aug 2017 06:31:31 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;

int main()
{
	log4cpp::OstreamAppender *osAppender = new log4cpp::OstreamAppender("osAppender", &cout);
	log4cpp::PatternLayout *pLayout = new log4cpp::PatternLayout();
	pLayout->setConversionPattern("%d: %p %c %x : %m %n");
	osAppender->setLayout(pLayout);

	log4cpp::Category &root = log4cpp::Category::getRoot();
	log4cpp::Category &infoCategory = root.getInstance("infoCategory");
	infoCategory.addAppender(osAppender);
	infoCategory.setPriority(log4cpp::Priority::INFO);

	infoCategory.info("system is running");
	infoCategory.warn("system has a warning");
	infoCategory.error("system has a error, cannot find a file");
	string longstr{"------ERROR has a error, cannot find a file, this length should must than 1024 byte,\n and longer than that, how to get a long string here, \nmust some ethom or pholosiphy content, here, and there. \nQ: Please tell me where to go, I must go one road to go. \nA: do you know where to go? Q: I donnot know. \nA: so walk to this way. Q: where are there? \nA: So what? Nothing to know, that's to go.'\n"};
	longstr += longstr;
	longstr += longstr;
	longstr += longstr;
	longstr += longstr;
	infoCategory.error(longstr);
	std::cout << longstr.length() << std::endl;
	infoCategory.fatal("system has a fatal error, must shutdown");
	infoCategory.info("system shutdown, you can find some information here");
	log4cpp::Category::shutdown();

	return 0;
}
