/*************************************************************************
	> File Name: message.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 11 May 2017 11:23:35 PM CST
 ************************************************************************/

#ifndef _MESSAGE_H__
#define _MESSAGE_H__

#include <iostream>

#include "info.hpp"

using namespace std;

/* start of namespace Anonymous */
namespace Anomynous{

	
	enum class MessageType{
		//ServiceMessage,
		Anomynous = 1,
		RegisterCustom,
		QueryCustom,
		QueryGroups,
		//CustomMessage,
		Connect, // connect to server.
		Disconnect, // disconnect to server.
		SendMsg, // send msg to id.
		//GroupMessage,
		JoinGroup,
		LeaveGroup,
	};

	class Message{
		MessageType type {MessageType::Anomynous};
		uint64_t source = 0; // custom id.
		uint64_t target = 0; // custom id or group id.
		string ssource {};
		string starget {};
		uint64_t at = 0; // arrive time.
		string msg {};
	public:
		Message() { }
		Message(MessageType ty, uint64_t s, uint64_t t, uint64_t a, string m){
			type = ty;
			source = s;
			target = t;
			at = a;
			msg = m;
		}

		Message(uint64_t s, uint64_t t, string m){
			source = s;
			target = t;
			msg = m;
		}
		Message(uint64_t s) { source = s; }

		int setType(int tp) { type = static_cast<MessageType> (tp); }
		int setSource(uint64_t s) { source = s; }
		int setTarget(uint64_t t) { target = t; }
		int setSource(string& s) { ssource = s; }
		int setTarget(string& t) { starget = t; }
		int setAt(uint64_t a) { at = a; }
		int setMsg(string& m) { msg = m; }

		int set(int tp, int tgt, string& msg){
			setType(tp);
			setTarget(tgt);
			setMsg(msg);
		}

		MessageType getType() { return type; }
		uint64_t getSourceID() { return source; }
		uint64_t getTargetID() { return target; }
		uint64_t getTime() { return at; }
		string getMsg() { return msg; }

		int dealToRegister(Info info){
			CustomerMap* custmap = info.getCustomerMap();
			Customer cust = info.getCustomer();
			uint64_t aid = cust.getID();
			cust.setID(target);
			Customer& ccc = custmap->mut.at(aid);

		}

		int deal(Info info){
			switch(type){
				case MessageType::Anomynous:
				case MessageType::sendMsg:
					dealToSendMsg(info);
					break;
				case MessageType::RegisterCustom:
				case MessageType::QueryCustom:
				case MessageType::QueryGroups:
				case MessageType::Connect:
				case MessageType::Disconnect:
				case MessageType::JoinGroup:
				case MessageType::LeaveGroup:
					dealToService(info);
					break;
				default:
					break;
			}
			return 0;
		}


		/* debug */
		int dealDebug(void)
		{
			switch(type)
			{
				case MessageType::Anomynous:{
												cout << "MessageType::Anomynous" << endl;
												cout << "message: " << msg << endl;
												break;
											}
				case MessageType::RegisterCustom:{
													 cout << "MessageType::RegisterCustom" << endl;
													 break;
												 }
				case MessageType::QueryCustom:{
												  cout << "MessageType::QueryCustom" << endl;
												  break;
											  }
				case MessageType::QueryGroups:{
												 cout << "MessageType::QueryGroups" << endl;
												 break;
											 }
				case MessageType::Connect:{
											  cout << "MessageType::Connect" << endl;
											  break;
										  }
				case MessageType::Disconnect:{
												 cout << "MessageType::Disconnect" << endl;
												 break;
											 }
				case MessageType::SendMsg:{
												   cout << "MessageType::SendMsg" << endl;
												   break;
											   }
				case MessageType::JoinGroup:{
										   cout << "MessageType::JoinGroup" << endl;
										   break;
									   }
				case MessageType::LeaveGroup:{
											cout << "MessageType::LeaveGroup" << endl;
											break;
										}
			}
		}

		/* debug */
		string toString(void){
			string shead("Message: ");
			string stype ("type=");
			string ssource (", source=");
			string starget (", target=");
			string sat (", arriveTime=");
			string smsg (", msg=");
			string sendl (";");

			string ret = shead + stype + to_string(static_cast<int>(type)) + ssource + to_string(source) + starget + to_string(target) + sat + to_string(at) + smsg + msg + sendl;

			return ret;
		}

		~Message() { }
	};



}; /* end of namespace anomynous. */


#endif

