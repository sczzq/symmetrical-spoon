#include "cpp_header.h"

class Solution {
	vector<int> mw;
	int rdm;
public:
	Solution(vector<int>& w){
		mw = vector<int>(w.size(), 0);
		mw[0] = w[0];
		for(int i = 1; i < w.size(); i++)
		{
			mw[i] = mw[i-1]+w[i];
		}
		rdm = 1;
	}

	int pickIndex()
	{
		rdm++;
		rdm %= mw.back();
		if(rdm <= mw.front())
		{
			return 0;
		}
		for(int i = 1; i < mw.size(); i++)
		{
			if(rdm > mw[i-1] && rdm <= mw[i])
			{
				return i;
			}
		}
	}
};

int main()
{
	vector<int> w{3,3};
	Solution sol(w);

	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";
	cout << sol.pickIndex() << "\n";

}


