#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int countSubstrings(string s)
	{
		int count = s.length();
		for(int i = 0; i < s.length(); i++)
		{
			for(int j = i + 1; j < s.length(); j++)
			{
				int same = 1;
				for(int k = 0; k < (j-i+1)/2; k++)
				{
					if(s[i+k] != s[j-k])
					{
						same = 0;
						break;
					}
				}
				if(same == 1)
				{
					count++;
				}
			}
		}

		return count;
	}

	int countSubstrings2(string s)
	{
		int len = s.length();
		int count = len;
		string ds;
		ds += s[0];
		for(int i = 1; i < s.length(); i++)
		{
			ds += '.';
			ds += s[i];
		}

		cout << ds << "\n";

		int dslen = ds.length();
		for(int i = 1; i < ds.length(); i++)
		{
			int width = min(i, (dslen - i));

			{
				int k;
				if(i % 2 == 0){
					k = 2;
				} else {
					k = 1;
				}
				for( ; k <= width; k+=2)
				{
					if(ds[i - k] == ds[i + k])
					{
						count++;
					}
					else
					{
						break;
					}
				}
			}
		}

		return count;
	}
};

int main()
{
	Solution s;
	string ss;

	ss = "abc";
	cout << s.countSubstrings2(ss) << "\n";

	ss = "aaa";
	cout << s.countSubstrings2(ss) << "\n";

	ss = "abc";
	cout << s.countSubstrings2(ss) << "\n";



}
