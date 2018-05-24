/*************************************************************************
	> File Name: pex510.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 02:00:04 PM CST
 ************************************************************************/

#include<iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs ("test.txt", ifstream::in);

	char c = ifs.get();

	while(ifs.good()){
		cout << c;
		c = ifs.get();
	}
	cout << endl;
	ifs.close();
	return 0;
}
