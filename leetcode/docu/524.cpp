#include "cpp_header.h"

class Solution {
public:
	string findLongestWord(string s, vector<string>& d)
	{
		string res;

		if(s.length() == 0)
		{
			return res;
		}

		for(auto & x : d)
		{
			if(is_contained(x, s))
			{
				if(res.length() < x.length())
				{
					res = x;
				}
				else if(res.length() == x.length() && res > x)
				{
					res = x;
				}
			}
		}

		return res;
	}

	// assume s1.length() < s2.length()
	bool is_contained(const string & s1, const string & s2)
	{
		int m = 0, n = 0;
		bool solo = false;

		if(s1.length() > s2.length())
			return solo;

		while(m < s1.length() && n < s2.length())
		{
			if(s1[m] != s2[n])
			{
				n++;
			}
			else
			{
				m++;
				n++;
			}
		}
		if(m == s1.length())
		{
			solo = true;
		}

		return solo;
	}
};

void testcase(string s, vector<string> d, string res, int casenum)
{
	Solution sol;

	cout << "------------------------\n";
	if(sol.findLongestWord(s, d) == res)
	{
		cout << casenum << " passed\n";
	}
	else
	{
		cout << casenum << " no pass\n";
		cout << "detains: \n";
		cout << s << "\n";
		for(auto x : d)
			cout << x << "  ";
		cout << "\n";
	}
	cout << "--------------------------------------\n";

}

int main()
{
	string s;
	vector<string> d;
	string res;
	int casenum;

	s = "abpcpalea";
	d = {"ale", "apple", "monkey", "plea"};
	res = "apple";
	casenum = 1;
	
	testcase(s, d, res, casenum);

	s = "abpcpalea";
	d = {"a", "b", "c"};
	res = "a";
	casenum = 2;
	
	testcase(s, d, res, casenum);

	s = "";
	d = {"a", "b", "c"};
	res = "";
	casenum = 3;
	
	testcase(s, d, res, casenum);

	s = "abc";
	d = {"aabcca", "baa", "ca"};
	res = "";
	casenum = 4;
	
	testcase(s, d, res, casenum);

	s = "abc";
	d = {"aabcca", "baa", "a", "ab", "bc"};
	res = "ab";
	casenum = 5;
	
	testcase(s, d, res, casenum);

	s = "abcd";
	d = {"ab", "bc", "c", "abc", "bcd"};
	res = "abc";
	casenum = 6;
	
	testcase(s, d, res, casenum);

	s = "bab";
	d = {"ba", "ab", "a", "b"};
	res = "ab";
	casenum = 7;
	
	testcase(s, d, res, casenum);

}


