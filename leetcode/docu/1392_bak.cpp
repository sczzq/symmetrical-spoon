#include "cpp_header.h"

class Solution {
public:
	string longestPrefix(string s)
	{
		if(s.length() <= 1)
		{
			return "";
		}

		// run length coding
		string run_length_code;
		vector<int> run_length;

		run_length_coder(s, run_length_code, run_length);


		if(run_length.size() == 1 && run_length[0] > 1) // just one character with or without duplicate
		{
			return s.substr(1);
		}


		string res;
		vector<int> first, last;

		for(int i = 0; i < run_length_code.length(); i++)
		{
			if(run_length_code[i] == run_length_code.front())
			{
				first.push_back(i);
			}
			
			if(run_length_code[i] == run_length_code.back())
			{
				last.push_back(i);
			}
		}

		if(last.size() == 1 || first.size() == 1)
		{
			return "";
		}

		/*
		cout << "first: ";
		for(auto x : first)
		{
			cout << x << " ";
		}
		cout << "\n";


		cout << "last: ";
		for(auto x : last)
		{
			cout << x << " ";
		}
		cout << "\n";
		*/








		if( (first.size() == 2)
				&& (run_length_code.front() == run_length_code.back()))
		{
			return s.substr(0, min(run_length[first[0]], run_length[first[1]]));
		}

		// check from big region to small region
		// the first equal string is result
		for(int i = 1; i < first.size(); i++)
		{
			int post_len = last.back() - first[i];
			bool equal = false;
			for(int j = last.size() - 1; j >= 0; j--)
			{
				int pre_len = last[j] - first.front();
//				cout << "pre post  " << pre_len << ", " << post_len << "\n";
//				cout << "i j " << i << ", " << j << "\n";
				if(post_len == pre_len) // character set sequence is same, then check its length
				{
					equal = true; // maybe true, need check after this.
					// prefix	run_length_code.front()	....	last[j]
					// postfix	first[i]				....	run_length_code.back()
					
					if(! (run_length.front() <= run_length[first[i]]) )
					{
//						cout << "1\n";
						equal = false;
						break;
					}
					for(int k = 1; k < last[j]; k++)
					{
						if(! ((run_length[k] == run_length[k+first[i]])
								&& (run_length_code[k] == run_length_code[k+first[i]])) )
						{
//							cout << "2\n";
							equal = false;
							break;
						}
					}
					if(! (run_length[last[j]] >= run_length.back()) )
					{
//						cout << "3\n";
						equal = false;
						break;
					}
					if(equal == false)
					{
						break;
					}
				}
			}
			if(equal)
			{
				int res_len = run_length[0];
				for(int j = first[i]+1; j < run_length.size(); j++)
				{
					res_len += run_length[j];
				}
				return s.substr(0, res_len);
			}
		}

		return "";
	}

	void run_length_coder(string& s, string& run_length_code, vector<int>& run_length)
	{
		for(int i = 0; i < s.length() - 1; )
		{
			for(int j = i + 1; j < s.length(); j++)
			{
				if(s[j] != s[i])
				{
					run_length_code += s[i];
					run_length.push_back(j - i);

					i = j;

					break;
				}
				if(j == s.length() - 1)
				{
					run_length_code += s[i];
					run_length.push_back(j - i + 1);
					i = j;
					break;
				}
			}
		}
		if(s.back() != run_length_code.back())
		{
			run_length_code += s.back();
			run_length.push_back(1);
		}

		/*

		cout << run_length_code << "\n";
		for(auto x : run_length)
		{
			cout << x << " ";
		}
		cout << "\n";
		*/
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

