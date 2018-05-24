/*************************************************************************
	> File Name: custom.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 12 May 2017 12:50:05 AM CST
 ************************************************************************/

#ifndef _CUSTOM_HPP_
#define _CUSTOM_HPP_

using namespace std;
#include <string>
#include <vector>
#include "connection.hpp"

namespace Anomynous{

	class Customer{
		uint64_t id {1234567890};
		uint64_t time {0};
		string name{"Anomynous"};
		Connection connection { };
	public:
		/* default construtor */
		Customer() { id = Anomynous::RandomUint64_t(); }
		/* parameter: id, time, name */
		Customer(uint64_t d, uint64_t t, string n) { id = d; time = t; name = n; }
		/* parameter: id, name */
		Customer(uint64_t d, string n) { id = d; name = n; }
		/* parameter: connection */
		Customer(Connection conn) {	
			id = Anomynous::RandomUint64_t();
			connection = conn;
		}

		int setID(uint64_t d){ id = d; }
		int setTime(uint64_t t) { time = t; }
		int setName(string n) { name = n; }
		int setConn(Connection conn) { connection = conn; }

		uint64_t getID() { return id; }
		uint64_t getTime() { return time; }
		string getName() { return name; }
		Connection getConn() { return connection; }

		/* debug */
		string toString(void){
			string scus {"Customer: cid="};
			string sname {", name="};
			string stime {", time="};
			string sendl {";"};
			return scus + to_string(id) + sname + name + stime + to_string(time) + sendl;
		}

	};

	class Group{
		uint64_t id {9876543210};
		uint64_t time;
		string name {"Anomynous"};
		vector<uint64_t> customs {};
	public:
		Group() { }
		Group(uint64_t d, uint64_t t, string n){
			id = d;
			time = t;
			name = n;
		}

		int setID(uint64_t d) { id = d; }
		int setTime(uint64_t t) { time = t; }
		int setName(string n) { name = n; }

		uint64_t getID() { return id; }
		uint64_t getTime() { return time; }
		string getName() { return name; }
		vector<uint64_t>& getCustomers(){ return customs; }

		int add(Customer c) { customs.push_back(c.getID()); }

		int del(uint64_t id){
		}

	};
};

#endif

