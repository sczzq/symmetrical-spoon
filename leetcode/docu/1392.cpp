#include "cpp_header.h"

class Solution {
public:
	string longestPrefix(string s)
	{
		int k = -1;
		vector<int> next(s.length());

		next[0] = -1;

		for(int q = 1; q < s.length(); q++)
		{
			k = next[q-1];
			while( ( s[k+1] != s[q]) && k>=0 )
			{
				k = next[k];
			}
			if(s[k+1] == s[q])
			{
				next[q] = k + 1;
			}
			else{
				next[q] = -1;
			}
		}

		return s.substr(0, next.back() + 1);
	}

};

int main()
{
	string s {"level"};

	Solution solu;

	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "ababab";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "leetcodeleet";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "leet";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "ab";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "abab";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "abbab";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaab";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaabb";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaabbcc";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaabbcca";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaabbccaa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaabbccaaa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaabbccaaab";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaabbccaaabb";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aabaaabb";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aabbaaab";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aabbccaaabbc";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "a";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aaaa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "ababbabbbabbbbaabaabbabbbaabbbaabbbb";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "babbb";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "abbaa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "abca";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aabca";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aabcaaa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "ababa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "aabaabaa";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

	s = "abaabacb";
	cout << s << "\n";
	cout << solu.longestPrefix(s) << "\n";
	cout << "--------------------------------\n";

#include "1392_testcase"
	cout << s.length() << "\n";
	//solu.longestPrefix(s);
	//cout << solu.longestPrefix(s) << "\n";

#include "1392_testcase2"
	cout << s.length() << "\n";
	solu.longestPrefix(s);
	//cout << solu.longestPrefix(s) << "\n";

}

