/*************************************************************************
	> File Name: example2.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 22 May 2017 05:32:57 PM CST
 ************************************************************************/

#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::string line;
	boost::regex pat ("^Subject: (Re: | Aw: )*(.*)");

	while(std::cin){
		std::getline(std::cin, line);
		boost::smatch matches;
		if(boost::regex_match(line, matches, pat))
			std::cout << matches[2] << std::endl;
	}

	return 0;
}

