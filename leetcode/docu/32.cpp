#include "cpp_header.h"

class Solution {
public:
	int longestValidParentheses(string s)
	{
		int dp[s.length()+1] = {0};
		int res = 0;

		for(int i = 2; i <= s.length(); i++)
		{
			if(s[i-1] == ')')
			{
				if(s[i-2] == '(')
				{
					dp[i] = dp[i-2] + 2;
				}
				else
				{
					if((i-dp[i-1]-2) >= 0 && s[i-dp[i-1]-2] == '(')
						dp[i] = dp[i-1] + 2 + dp[i-dp[i-1] - 2];
				}
				if(res < dp[i])
					res = dp[i];
			}
		}

		return res;
	}

	int longestValidParentheses2(string s)
	{
		int max_len = 0;
		for(int i = 1; i < s.length(); i++)
		{
			if(s[i] == ')')
			{
				for(int j = i-1; j >= 0; j-=2)
				{
					if(s[j] == ')')
						break;
					else if(s[j] == 0)
						continue;
					else if(s[j] == '(')
					{
						s[j] = 0;
						s[i] = 0;
						break;
					}
				}
			}
		}


		/*
		for(int i = 0; i < s.length(); i++)
			cout << s[i] << " ";
		cout << "\n-----------------\n";
		*/

		for(int i = 0; i < s.length(); )
		{
			if(s[i] == 0)
			{
				int zero_len = 0;
				for(int j = i; j < s.length(); j++)
				{
					if(s[j] == 0)
					{
						zero_len++;
					}
					else
						break;
				}
				if(max_len < zero_len)
					max_len = zero_len;
				i += zero_len;
			}
			else
				i++;
		}

		return max_len;
	}
};

int main()
{
	string s;
	int res;
	int casenum;

	s = "((()))";
	res = 6;
	casenum = 1;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "((())";
	res = 4;
	casenum = 2;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "((((((";
	res = 0;
	casenum = 3;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "))))))";
	res = 0;
	casenum = 4;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "()(()";
	res = 2;
	casenum = 5;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "()(()()";
	res = 4;
	casenum = 6;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "()((())";
	res = 4;
	casenum = 7;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "()((())()";
	res = 6;
	casenum = 8;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "()((())(()";
	res = 4;
	casenum = 9;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "()((())(()))";
	res = 12;
	casenum = 10;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = ")((())(())";
	res = 8;
	casenum = 11;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

	s = "())";
	res = 2;
	casenum = 12;
	TESTCASE_p1(longestValidParentheses, s, res, casenum);

}

