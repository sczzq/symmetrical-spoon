#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
	int numDecodings(string s)
	{
		vector<int> single_tail(10, 0);
		int double_tail = 0;
		for(auto c : s)
		{
			switch (c)
			{
				case '0':
					;;
				case '1':
					;;
				case '2':
					;;
				case '3':
					;;
				case '4':
					;;
				case '5':
					;;
				case '6':
					;;
				case '7':
				case '8':
				case '9':
					;;
				case '*':
					;;
				default:
					;;
			}
		}
	}
};

int main()
{
	Solution sol;
	string s = "1**";

	sol.numDecodings(s);
}


