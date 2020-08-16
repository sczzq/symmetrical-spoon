#include "cpp_header.h"

class Solution 
{
	struct customGreater1 {
		bool operator()(const string & a, const string & b) const
		{
			return a.length() > b.length();
		}
	} ;

	struct  {
		bool operator()(const string & a, const string & b) const
		{
			return a.length() > b.length();
		}
	} customGreater2;
public:
	int findLUSlength(vector<string> strs)
	{
		int res = -1;

		if(strs.size() > 0)
		{
			sort(strs.begin(), strs.end(), customGreater2); // nlgn

			unordered_map<string, int> str_count;

			for(auto & s : strs)
			{
				str_count[s]++;
			}

			auto last = unique(strs.begin(), strs.end()); // n
			strs.erase(last, strs.end());

			/*
			cout << "--------------------------\n";
			for(auto x : str_count)
			{
				cout << x.first << ", " << x.second << "\n";
			}
			cout << "--------------------------\n";
			*/


			for(auto it = strs.begin(); it != strs.end(); it++)
			{
				if(str_count[*it] == 1)
				{
					bool is_solo = true;
					for(auto it2 = strs.begin(); it2 != it; it2++)
					{
						if(is_contained(*it, *it2))
						{
							is_solo = false;
							break;
						}
					}
					if(is_solo)
					{
						res = it->length();
						break;
					}
				}
			}
		}

		return res;
	}

	// time: O(n)
	// memory: O(1)
	bool is_contained(const string & s1, const string & s2)
	{
		int m = 0, n = 0;
		bool res = false;
		while( m < s1.length() && n < s2.length() )
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
			res = true;
		}

		return res;
	}
};

bool testcase(vector<string> strs, int res, int casenum)
{
	Solution sol;

	if( sol.findLUSlength(strs) == res )
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
		cout << "detail:\n";
		for(auto & s : strs)
		{
			cout << s << "--  ";
		}
		cout << "\n";
	}

	cout << "-----------------------------------------\n";
}

int main()
{
	vector<pair<vector<string>, int>> cases;
	vector<string> strs;

	
	strs = {"abc", "abd", "bcd"};
	cases.push_back(make_pair(strs, 3));


	strs = {"a", "ab", "bc", "abc", "b", "c", "bcd"};
	cases.push_back(make_pair(strs, 3));

	strs = {"a", "ab", "bc", "abc", "b", "c", "bcd", "abc", "bcd"};
	cases.push_back(make_pair(strs, -1));

	strs = {"a", "bcd"};
	cases.push_back(make_pair(strs, 3));

	strs = {"a", "a", "a", "a", "a"};
	cases.push_back(make_pair(strs, -1));

	strs = {"a", "a", "v", "v", "v"};
	cases.push_back(make_pair(strs, -1));

	strs = {"a", "a", "b", "v", "v"};
	cases.push_back(make_pair(strs, 1));

	strs = {"aaa", "aaa", "ba", "va", "vaaaaaaaaaaaaaaaaaaaa"};
	cases.push_back(make_pair(strs, 21));

	strs = {"aaa", "aaa", "ba", "va", "vaaaa", "vaaaa", "ab"};
	cases.push_back(make_pair(strs, 2));

	strs = {"", ""};
	cases.push_back(make_pair(strs, -1));

	strs = {"a", "", ""};
	cases.push_back(make_pair(strs, 1));

	strs = {"aa", "ab"};
	cases.push_back(make_pair(strs, 2));

	int num = 1;
	for(auto & x : cases)
	{
		testcase(x.first, x.second, num);
		num++;
	}

	/*
	strs = {"a", "b", "c", "d", "e", 
		"ab", "ac", "ad", "ae", "bc", "bd", "be", "cd", "ce",
		"ba", "ca", "da", "ea", "cb", "db", "eb", "dc", "ec",
		"abc", "abd", "abe", "acd", "ace", "ade",
		"acb", "adb", "aeb", "adc", "aec", "aed",
		"bca", "bad", "bae", "cad", "cae", "dae",
		"bac", "bda", "bea",
		"cab", "dab", "eab",
		"cba", "dba", "eba",
		"abcd", "abce", "aced",
		"abcde", "abcde"
	};
	testcase(strs, -1, 3);
	*/

}

