#include "cpp_header.h"

class KMP {
	vector<vector<int>> dp;
	string pattern;
public:
	KMP(const string & s) : pattern(s) {
		construct();
	}

	void construct()
	{
		dp = vector<vector<int>>(pattern.length(), vector<int>(256, 0));
		dp[0][pattern[0]] = 1;
		int X = 0;
		for(int j = 1; j < pattern.length(); j++)
		{
			for(int c = 0; c < 256; c++)
			{
				dp[j][c] = dp[X][c];
			}
			dp[j][pattern[j]] = j + 1;
			X = dp[X][pattern[j]];
		}
	}

	void setPattern(const string & s)
	{
		pattern = s;
		construct();
	}

	int search(string target)
	{
		int j = 0;
		for(int i = 0; i < target.length(); i++)
		{
			j = dp[j][target[i]];
			if(j == pattern.length()) return i - pattern.length() + 1;
		}

		return -1;
	}
};

int main()
{
	string pattern = "bbba";
	string target {"bbbcbbba"};

	KMP kmp(pattern);
	kmp.construct();

	cout << kmp.search(target) << "\n";

}



