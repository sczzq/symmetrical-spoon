#include "cpp_header.h"

class Solution {
public:
	int longestCommonSubstring(string A, string B)
	{
		if(A.length() == 0 || B.length() == 0) return 0;
		cout << A << "\n";
		cout << B << "\n";

		vector<vector<int>> res(A.length(), vector<int>(B.length(), 0));
		res[0][0] = A[0] == B[0] ? 1 : 0;
		int imax = res[0][0];

		for(int i = 1; i < A.length(); i++)
		{
			res[i][0] = A[i] == B[0] ? 1 : 0;
			imax = max(imax, res[i][0]);
		}

		for(int j = 1; j < B.length(); j++)
		{
			res[0][j] = B[j] == A[0] ? 1 : 0;
			imax = max(imax, res[0][j]);
		}

		for(int i = 1; i < A.length(); i++)
		{
			for(int j = 1; j < B.length(); j++)
			{
				if(A[i] == B[j])
				{
					res[i][j] = res[i-1][j-1] + 1;
					imax = max(imax, res[i][j]);
				}
				else
				{
					res[i][j] = 0;
				}
			}
		}

		show_vector(res);

		return imax;
	}

	void show_vector(vector<vector<int>> vv)
	{
		for(auto v : vv)
		{
			for(auto c : v)
			{
				cout << c << " ";
			}
			cout << "\n";
		}
	}
};

int main()
{
	string A{"abcd"}, B{"abcd"};

	Solution s;
	cout << s.longestCommonSubstring(A, B) << "\n";

	A = "abddddd";
	B = "dddd";
	cout << s.longestCommonSubstring(A, B) << "\n";

	A = "abcdefghijklmn";
	B = "fghilmn";
	cout << s.longestCommonSubstring(A, B) << "\n";


}

