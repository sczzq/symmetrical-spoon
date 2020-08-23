#include "cpp_header.h"

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if(strs.size() == 0)
			return "";

		for(int i = 0; i < strs[0].length(); i++)
		{
			for(int j = 1; j < strs.size(); j++)
			{
				if(strs[j-1].length() <= i || strs[j].length() <= i)
					return strs[0].substr(0, i);
				if(strs[0][i] != strs[j][i])
					return strs[0].substr(0, i);
			}
		}

		return strs[0];
	}
};

int main()
{
	vector<string> strs;
	string res;
	int casenum;

	strs = {"flower", "flow", "flight"};
	res = "fl";
	casenum = 1;
	TESTCASE_p1(longestCommonPrefix, strs, res, casenum);

	strs = {"dog", "racecar", "car"};
	res = "";
	casenum = 2;
	TESTCASE_p1(longestCommonPrefix, strs, res, casenum);

	strs = {"dog", "dog", "dog"};
	res = "dog";
	casenum = 3;
	TESTCASE_p1(longestCommonPrefix, strs, res, casenum);

	strs = {"dog"};
	res = "dog";
	casenum = 4;
	TESTCASE_p1(longestCommonPrefix, strs, res, casenum);
}


