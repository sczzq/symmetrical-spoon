/*************************************************************************
	> File Name: test_string_literal.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 02 May 2017 03:34:07 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int f()
{
	const char* s = "hello wolrd!"  "too stupid";
	cout << s << '\n';

	const char* s2 = "hello world!  \
		toooooo stupid";
	cout << s2 << "\n";

	const char* s3 = R"(hello world \n
		too stupid)";

	cout << s3 << "\n";

}

int main()
{
	f();
}
