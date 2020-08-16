#include "cpp_header.h"

class Solution {
public:
	string frequencySort(string s)
	{
		map<char, int> freq;
		multimap<int, char, greater<int>> chars;
		for(auto x : s)
			freq[x]++;
		for(auto &x : freq)
			chars.emplace(x.second, x.first);
		s = "";
		for(auto & x : chars)
			for(int i = 0; i < x.first; i++)
				s += x.second;

		return s;
	}
};

int main()
{
	Solution sol;

	string s;

	s = "ababab";
	cout << sol.frequencySort(s) << "\n";

	s = "abccc";
	cout << sol.frequencySort(s) << "\n";

	s = "Aabb";
	cout << sol.frequencySort(s) << "\n";

	s = "abacc";
	cout << sol.frequencySort(s) << "\n";

	s = "a";
	cout << sol.frequencySort(s) << "\n";

	s = "";
	cout << sol.frequencySort(s) << "\n";

}

