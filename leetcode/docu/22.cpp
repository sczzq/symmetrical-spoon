#include "cpp_header.h"

/* 
 * n n
 * n-1 1 1 n-1 
 * n-2 2 2 n-2
 * n-2 1 2 n-3
 *
 * n-3 3 3 n-3
 * n-3 2 
 *
 * 2 -2
 * 1 -1 1 -1
 *
 * 3 -3
 * 2 -1 1 -2
 * 2 -2 1 -1
 * 1 -1 2 -2
 * 1 -1 1 -1 1 -1
 *
 * 4 -4
 * 1 -1 3 -3
 * 3 -1 1 -3 
 * 3 -3 1 -1
 * 1 -1 2 -1 1 -2
 * 2 -1 1 -1 1 -2
 * 2 -1 1 -2 1 -1
 * 1 -1 2 -2 1 -1
 * 2 -1 1 -2 1 -1
 * 2 -2 1 -1 1 -1
 * 1 -1 1 -1 2 -2
 * 1 -1 1 -1 1 -1 1 -1
 *
 */

class Solution {
public:
	vector<string> generateParenthsis2(int n)
	{
		set<list<int>, greater<list<int>>> res;
		set<list<int>, greater<list<int>>> res2;
		if(n == 1) return {"()"};

		res = {{2,-2},{1,-1,1,-1}};
		res2 = res;

		for(int i = 3; i <= n; i++)
		{
			res = move(res2);
			for(auto &sit : res)
			{
				for(int k = 0; k <= (sit).size(); k++)
				{
					list<int> t = sit;

					auto it = t.begin();
					for(int l = 0; l < k; l++)
						it++;

					t.insert(it, {1,-1});
					res2.insert(t);

					if(k > 0 && k != sit.size())
					{
						list<int> t = sit;
						auto it = t.begin();
						for(int l = 0; l < k; l++)
							it++;
						t.insert(it, {-1, 1});
						res2.insert(t);
					}
				}
			}
			res2.insert({i, 0-i});
		}

		set<string> sres;
		vector<string> pres;
		for(auto &sl : res2)
		{
			string s;
			int sum = 0;
			for(auto i : sl)
			{
				if(sum < 0)
					break;
				if(i > 0)
				{
					sum += i;
					while(i--)
						s += '(';
				}
				else
				{
					sum += i;
					while(i++)
						s += ')';
				}
			}
			if(sum >= 0)
				sres.insert(s);
		}

		pres.insert(pres.end(), sres.begin(), sres.end());

		//sort(pres.begin(), pres.end());

		for(auto & sl : res2)
		{
			for(auto j : sl)
				cout << j << "  ";
			cout << "\n";
		}

		for(auto s : pres)
			cout << s << "\n";

		cout << "-------------------------------------\n";

		return pres;
	}

	vector<string> generateParenthsis(int n)
	{
		vector<int> vs;
		int i = n;
		while(i--)
			vs.push_back(-1);
		i = n;
		while(i--)
			vs.push_back(1);

//		sort(vs.begin(), vs.end());

		vector<string> res;

		do {
			int cs = 0;
			string s;
			for(auto i : vs)
			{
				if(cs < 0)
					break;
				cs += i;

				if(i == 1)
					s += '(';
				else if(i == -1)
					s += ')';
			}
			if(cs >= 0)
			{
//				cout << s << "\n";
				res.push_back(s);
			}
		} while(std::next_permutation(vs.begin(), vs.end()));

		return res;
	}


	vector<string> generateParenthsis4(int n)
	{
		string s;
		int i = n;
		while(i--)
			s += '(';
		i = n;
		while(i--)
			s += ')';

		vector<string> res;

		do {
			int cs = 0;
			for(auto c : s)
			{
				if(c == '(')
					cs++;
				else
					cs--;
				if(cs < 0)
					break;
			}
			if(cs >= 0)
				res.push_back(s);

		} while(std::next_permutation(s.begin(), s.end()));

		return res;
	}



};

int main()
{
	int n;
	vector<string> res;
	int casenum;

	n = 3;
	res = {"((()))", "(()())", "(())()", "()(())", "()()()"};
	casenum = 1;
	TESTCASE_p1(generateParenthsis, n, res, casenum);

	n = 2;
	res = {"(())", "()()"};
	casenum = 2;
	TESTCASE_p1(generateParenthsis, n, res, casenum);

	n = 4;
	res = {"(())", "()()"};
	casenum = 3;
	TESTCASE_p1(generateParenthsis, n, res, casenum);

	n = 9;
	res = {"(())", "()()"};
	casenum = 4;
	TESTCASE_p1(generateParenthsis, n, res, casenum);

	n = 8;
	res = {"(())", "()()"};
	casenum = 4;
	TESTCASE_p1(generateParenthsis, n, res, casenum);

	n = 7;
	res = {"(())", "()()"};
	casenum = 4;
	TESTCASE_p1(generateParenthsis, n, res, casenum);


}

