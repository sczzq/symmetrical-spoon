/*************************************************************************
	> File Name: pex65.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 03:46:34 PM CST
 ************************************************************************/

#include <iostream>
#include <boost/regex.hpp>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string s;
	boost::smatch m;
	boost::regex e("a+");

	ifstream ifs ("test.txt", ifstream::in);

	char c = ifs.get();
	while(ifs.good()){
		do{
			if(c == '\n'){
				c = ifs.get();
				continue;
			}
			s.append(1, c);
			c = ifs.get();
		}while(ifs.good() && c!='\n');

		cout << s << endl;

//		while(regex_search(s,m,e)){
//			for(auto x : m) cout << x << " ";
//			s = m.suffix().str();
//		}

		s.erase();
	}

	ifs.close();
}
