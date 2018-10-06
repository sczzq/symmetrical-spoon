/*************************************************************************
    > File Name: calculate.cpp
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年08月19日 星期日 11时15分07秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<stdlib.h>
using namespace std;

int calculate(string s)
{
	stack<int> nums;
	stack<char> ops;

	int i = 0;
	int nn = 0;
	string nstr, nstr2;
	for (i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			nn = ::atoi(nstr.c_str());
			nstr.clear();

			if (ops.size() > 0 && (ops.top() == '*' || ops.top() == '/')) {
				char c_op = ops.top();
				if ( c_op == '*') {
					nums.top() = nums.top() * nn;
				}
				else if (c_op == '/') {
					nums.top() = nums.top() / nn;
				}
				ops.pop();
			}
			else {
				nums.push(nn);
			}

		}
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			ops.push(c);
		}
		else if (c == ' '){
			;
		} else {
			nstr += c;
		}
	}
	if (nstr.length() > 0) {
		nn = ::atoll(nstr.c_str());
		nstr.clear();
		if (ops.size() > 0 && (ops.top() == '*' || ops.top() == '/')) {
			if (ops.top() == '*') {
				nums.top() *= nn;
			} else if (ops.top() == '/') {
				nums.top() /= nn;
			}
			ops.pop();
		} else {
			nums.push(nn);
		}
	}
	stack<int> numss;
	stack<char> opss;
	while(nums.size() > 0) {
		numss.push(nums.top());
		nums.pop();
	}
	while(ops.size() > 0) {
		opss.push(ops.top());
		ops.pop();
	}
	int result = 0;
	if (numss.size() > 0) {
		result = numss.top();
		numss.pop();
		cout << result << endl;
		while(numss.size() > 0 && opss.size() > 0) {
			char c = opss.top();
			if (c == '+') {
				result += numss.top();
			}
			else {
				result -= numss.top();
			}
			opss.pop();
			numss.pop();
			cout << result << endl;
		}
	}
	return result;
}

int main()
{
	string s ("3+2*2");
	cout << s << ": " << endl;;
	cout << calculate(s) << endl;

	s = " 3/2 ";
	cout << s << ": " << endl;;
	cout << calculate(s) << endl;

	s = " 3/2  + 123";
	cout << s << ": " << endl;;
	cout << calculate(s) << endl;

	s = " 3+5 / 2 ";
	cout << s << ": " << endl;;
	cout << calculate(s) << endl;

	s = "0-2147483647";
	cout << s << ": " << endl;;
	cout << calculate(s) << endl;

	s = "1-1+1";
	cout << s << ": " << endl;;
	cout << calculate(s) << endl;
}
