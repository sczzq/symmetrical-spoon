/*************************************************************************
	> File Name: parser.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 13 May 2017 05:58:05 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

#include "message.hpp"

using namespace std;

namespace Anomynous{
	class Message;

	int parseToMsg(Message& msg, string& str){
		size_t pos = str.find(":"), pos2;
		int type;
		string name;
		string str_msg;
		if(pos != std::string::npos){
			type = std::stoi(str.substr(0, pos));
			msg.setType(type);
		} else {
			return 0;
		}
		pos2 = str.find(":", pos+1);
		if(pos2 != std::string::npos){
			name = str.substr(pos+1, pos2);
			msg.setTarget(std::stoi(name));
			pos = str.find(":", pos2+1);
			if(pos2 != std::string::npos){
				str_msg = str.substr(pos2+1, pos);
				msg.setMsg(str_msg);
			} else {
			}
		} else {
		}
	}
};

