#include "cpp_header.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		int length = 0;

		char mark[128];
		int indexes[128];
		memset(indexes, 0, sizeof(indexes));
		memset(mark, 0, sizeof(mark));

		int sublen = 0;

		// aabb
		// abbb
		for(int i = 0; i < s.length(); i++)
		{
			if(mark[s[i]] != 0)
			{
				if(length < sublen)
					length = sublen;
				sublen = 0;
				i = indexes[s[i]];
				memset(mark, 0, sizeof(mark));
			}
			else
			{
				sublen++;
				mark[s[i]] = 1;
			}
			indexes[s[i]] = i;
		}

		if(length < sublen)  length = sublen;


		return length;
	}
};

int main()
{
	string s;
	int res;
	int casenum;

	s = "abcabcabc";
	res = 3;
	casenum = 1;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "bbbbb";
	res = 1;
	casenum = 2;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "pwwkew";
	res = 3;
	casenum = 3;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "abccdccabccabcc";
	res = 3;
	casenum = 4;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "abccdccabccabcdc";
	res = 4;
	casenum = 5;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "bba";
	res = 2;
	casenum = 6;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "abbb";
	res = 2;
	casenum = 7;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "aabbaabb";
	res = 2;
	casenum = 8;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "aabb";
	res = 2;
	casenum = 9;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "aabbcdab";
	res = 4;
	casenum = 10;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "abcabcd";
	res = 4;
	casenum = 11;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "abcbc";
	res = 3;
	casenum = 12;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "abbcbc";
	res = 2;
	casenum = 13;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);

	s = "abcbdefc";
	res = 5;
	casenum = 14;
	TESTCASE_p1(lengthOfLongestSubstring, s, res, casenum);


}


