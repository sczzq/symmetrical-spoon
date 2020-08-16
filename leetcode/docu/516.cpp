#include "cpp_header.h"

class Solution {
public:
	int longestPalindromeSubseq(string s)
	{
		int max_len = 0;

		if(s.length() < 2)
		{
			return s.length();
		}

		string ds;
		for(int i = 0; i < s.length(); i++)
		{
			ds += s[i];
			ds += ".";
		}

		cout << ds << "\n";

		for(int i = 1; i < ds.length() - 1; i++)
		{
			cout << "---------------------------------\n";
			int cur_len = 0;
			if(i % 2 == 1)
			{
				cur_len = checkDeeper(ds, i - 1, i + 1, cur_len);
			}
			else if(i % 2 == 0)
			{
				cur_len = checkDeeper(ds, i - 2, i + 2, cur_len);
				cur_len++;
			}
			if(cur_len > max_len)
			{
				max_len = cur_len;
			}
			cout << i << " : " << cur_len << "\n";
			cout << "---------------------------------\n";
		}

		cout << "---------------------------------\n";

		return max_len;
	}

	int checkDeeper(string & s, int left, int right, int length)
	{
		if(s[left] == s[right])
		{
			length += 2;
			cout << left << ", " << right << ", equal, length " << length << "\n";

			if((left - 2) >= 0 && (right + 2) < s.length())
			{
				cout << " To Left Right: \n";
				length = checkDeeper(s, left - 2, right + 2, length);
			}
		}
		else
		{
			int l_len = length, r_len = length;
			if(left-2 >= 0)
			{
				cout << "To left: \n";
				l_len = checkDeeper(s, left-2, right, length);
			}
			if(right + 2 < s.length())
			{
				cout << "To right: \n";
				r_len = checkDeeper(s, left, right+2, length);
			}
			length = max(l_len, r_len);
		}
		return length;
	}
};

int main()
{
	Solution ss;
	string s {"bbbab"};

	cout << ss.longestPalindromeSubseq(s) << "\n";

	s = "cbbd";
	cout << ss.longestPalindromeSubseq(s) << "\n";

	s = "bb";
	cout << ss.longestPalindromeSubseq(s) << "\n";

	s = "ab";
	cout << ss.longestPalindromeSubseq(s) << "\n";


}


