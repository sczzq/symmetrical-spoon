#include "cpp_header.h"

class Solution {
public:
	int findSubstringInWraproundString(string p)
	{
		vector<vector<char>> subs(26, vector<char>(p.length()+1, 0));

		if(p.length() < 2)
			return p.length();

		int i = 0, j = 0;
		while(i < p.length() - 1)
		{
			while(p[j]+1 == p[j+1] || p[j]+1 == p[j+1]+26)
				j++;

			j++;

			for( ; i < j; i++)
				for(int k = 1; k <= j - i; k++)
					subs[p[i]-'a'][k] = 1;
		}

		if(i < p.length())
			subs[p[i]-'a'][1] = 1;

		int count = 0;
		for(int i = 0; i < 26; i++)
			for(int j = 0; j <= p.length(); j++)
				if(subs[i][j] == 1)
					count++;

		return count;
	}

	int findSubstringInWraproundString2(string p)
	{
		vector<int> subs(26,0);

		if(p.length() < 2)
			return p.length();

		int i = 0, j = 0;
		while(i < p.length() - 1)
		{
			while(p[j]+1 == p[j+1] || p[j]+1 == p[j+1]+26)
				j++;

			j++;

			for( ; i < j; i++)
				subs[p[i]-'a'] = max(j - i, subs[p[i]-'a']);
		}

		if(i < p.length())
			subs[p[i]-'a'] = max(1, subs[p[i]-'a']);

		int count = 0;
		for(int i = 0; i < 26; i++)
			count += subs[i];

		return count;
	}



	// sub_nums[i] = sub_nums[i-1] + i
	// sub_nums[0] = 0
	// sub_nums[1] = 1
	int get_sub_nums(int length, vector<int>& sub_nums)
	{
		if(sub_nums.size() > length)
		{
			return sub_nums[length];
		}


		int sub_num = get_sub_nums(length - 1, sub_nums) + length;
		sub_nums.push_back(sub_num);

		return sub_num;
	}

	void get_subs(string& str, int start, int len, vector<vector<char>>& subs)
	{
		for(int i = start; i < (len + start); i++)
		{
			for(int j = 1; j <= (len - (i - start)); j++)
			{
				subs[str[i]-'a'][j] = 1;
			}
		}
	}
};

int testcase(string p, int res, int casenum)
{
	Solution sol;

	if(sol.findSubstringInWraproundString2(p) == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
	}
}

int main()
{
	string p;
	int res;
	int casenum;

	p = "a";
	res = 1;
	casenum = 1;
	testcase(p, res, casenum);

	p = "cac";
	res = 2;
	casenum = 2;
	testcase(p, res, casenum);

	p = "zab";
	res = 6;
	casenum = 3;
	testcase(p, res, casenum);

	p = "zabq";
	res = 7;
	casenum = 4;
	testcase(p, res, casenum);

}


