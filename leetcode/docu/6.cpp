#include "cpp_header.h"

class Solution {
public:
	string convert(string s, int numRows)
	{
		// boundary line.
		if(s.length() < 3 || numRows < 2) return s;

		string res;
		int line = 0;
		int circle = numRows * 2 - 2;
		for(int line = 0; line < numRows; line++)
		{
			for(int i = 0;   ; i++)
			{
				int index = i*circle + line;
				if(index >= s.length())
					break;
				res += s[index];
				if(line != 0 && line != numRows - 1)
				{
					index += circle - 2*line;
					if(index < s.length())
						res += s[index];
				}
			}
		}

		return res;
	}
};

int main()
{
	string s;
	string res;
	int numRows;
	int casenum;

	s = "LEETCODEISHIRING";
	res = "LCIRETOESIIGEDHN";
	numRows = 3;
	casenum = 1;
	TESTCASE_p2(convert, s, numRows, res, casenum);

	s = "LEETCODEISHIRING";
	res = "LDREOEIIECIHNTSG";
	numRows = 4;
	casenum = 2;
	TESTCASE_p2(convert, s, numRows, res, casenum);

	s = "A";
	res = "A";
	numRows = 1;
	casenum = 3;
	TESTCASE_p2(convert, s, numRows, res, casenum);

	s = "AB";
	res = "AB";
	numRows = 1;
	casenum = 4;
	TESTCASE_p2(convert, s, numRows, res, casenum);

	s = "ABC";
	res = "ABC";
	numRows = 1;
	casenum = 5;
	TESTCASE_p2(convert, s, numRows, res, casenum);


}
