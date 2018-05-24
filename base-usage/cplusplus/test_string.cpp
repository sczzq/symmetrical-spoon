/*************************************************************************
	> File Name: test_string.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 25 Apr 2017 09:53:25 AM CST
 ************************************************************************/

#include <iostream> // cout  endl
#include <string> // string
using namespace std;

int test1(const string& str, const string& str2)
{
	std::cout << str.length() << std::endl;
	std::cout << str2.length() << std::endl;

	return 0;
}

int main(){
	string s{"12345566"};
	for(char c : s)
		cout << c;
	cout << endl;

	test1("", s);
	test1(s, "");
}

