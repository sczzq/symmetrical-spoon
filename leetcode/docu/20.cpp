#include "cpp_header.h"

class Solution {
public:
	bool isValid(string s)
	{
		stack<char> sta;

		for(auto c : s)
		{
			if(c == '(' || c == '{' || c == '[')
				sta.push(c);
			else
			{
				if(sta.empty())
					return false;
				if(c == ')' && sta.top() != '(')
					return false;
				else if(c == ']' && sta.top() != '[')
					return false;
				else if(c == '}' && sta.top() != '{')
					return false;
				sta.pop();
			}
		}

		if(sta.empty())
			return true;
		return false;
	}
};

int main()
{
	string s;
	bool res;
	int casenum;

	s = "()";
	res = true;
	casenum = 1;
	TESTCASE_p1(isValid, s, res, casenum);

	s = "()[]{}";
	res = true;
	casenum = 2;
	TESTCASE_p1(isValid, s, res, casenum);

	s = "([)]";
	res = false;
	casenum = 3;
	TESTCASE_p1(isValid, s, res, casenum);

	s = "([";
	res = false;
	casenum = 4;
	TESTCASE_p1(isValid, s, res, casenum);

	s = "([])";
	res = true;
	casenum = 5;
	TESTCASE_p1(isValid, s, res, casenum);

	s = "";
	res = true;
	casenum = 6;
	TESTCASE_p1(isValid, s, res, casenum);



}
