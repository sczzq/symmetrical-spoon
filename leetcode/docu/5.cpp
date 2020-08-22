#include "cpp_header.h"

/*
 * 1, define state
 * 2, state transimation function
 * 3, initialization condition
 * 4, output
 * 5, space optimization
 */

class Solution {
public:
	string longestPalindrome2(string s)
	{
		if(s.length() < 2)
			return s;

		int max_len = 1, start = 0, end;

		vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), 0));

		for(int i = 0; i < s.length(); i++)
			dp[i][i] = 1;

		for(int j = 1; j < s.length(); j++)
		{
			for(int i = 0; i < j; i++)
			{
				if(s[i] != s[j])
				{
					dp[i][j] = false;
				} else {
					if(j - i < 3)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i+1][j-1];
				}

				if(dp[i][j] && j - i + 1 > max_len)
				{
					max_len = j - i + 1;
					start = i;
				}
			}
		}

		return s.substr(start, max_len);
	}

	string longestPalindrome(string s)
	{
		if(s.length() < 2)
			return s;
		int max_len = 1, start = 0, end = 0;
		string ns = "!";
		for(auto c : s)
		{
			ns += c;
			ns += '!';
		}

		for(int i = 0; i < ns.length(); i++)
		{
			int j = 0;
			while(i-j >= 0 && i+j<ns.length())
			{
				if(ns[i - j] != ns[i + j])
					break;
				j++;
			}
			if(max_len < j)
			{
				end = i + j - 1;
				start = i - j + 1;
				max_len = j;
			}
		}

		string res;
		for(int i = start; i < end; i++)
			if(ns[i] != '!')
				res += ns[i];

		return res;
	}
};

int main()
{
	string s;
	string res;
	int casenum;

	s = "abccba";
	res = "abccba";
	casenum = 1;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "abcba";
	res = "abcba";
	casenum = 2;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "abba";
	res = "abba";
	casenum = 3;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "abbaa";
	res = "abba";
	casenum = 4;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "abcbaa";
	res = "abcba";
	casenum = 5;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "acbaa";
	res = "aa";
	casenum = 6;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "aaca";
	res = "aca";
	casenum = 7;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "abaca";
	res = "aba";
	casenum = 8;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "ab";
	res = "a";
	casenum = 9;
	TESTCASE_p1(longestPalindrome, s, res, casenum);

	s = "abcddcef";
	res = "cddc";
	casenum = 10;
	TESTCASE_p1(longestPalindrome, s, res, casenum);


}



