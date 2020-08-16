#include "cpp_header.h"

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		map<int, int> AB, CD;

		for(int i = 0; i < A.size(); i++)
		{
			for(int j = 0; j < B.size(); j++)
			{
				AB[A[i]+B[j]]++;
			}
		}

		for(int i = 0; i < C.size(); i++)
		{
			for(int j = 0; j < D.size(); j++)
			{
				CD[C[i]+D[j]]++;
			}
		}

		int count = 0;
		for(auto it = AB.begin(); it != AB.end(); it++)
		{
			if(CD.find(0 - (it->first)) != CD.end())
			{
				count += it->second * CD[0 - it->first];
			}
		}

		return count;
	}



	int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		map<int, int> AM, BM, CM, DM,  AB, CD;

		for(int i = 0; i < A.size(); i++)
			AM[A[i]]++;

		for(int i = 0; i < B.size(); i++)
			BM[B[i]]++;

		for(int i = 0; i < C.size(); i++)
			CM[C[i]]++;

		for(int i = 0; i < D.size(); i++)
			DM[D[i]]++;

		for(auto it = AM.begin(); it != AM.end(); it++)
			for(auto it2 =BM.begin(); it2 != BM.end(); it2++)
				AB[it->first + it2->first] += it->second * it2->second;

		for(auto it = CM.begin(); it != CM.end(); it++)
			for(auto it2 =DM.begin(); it2 != DM.end(); it2++)
				CD[it->first + it2->first] += it->second * it2->second;

		int count = 0;
		for(auto it = AB.begin(); it != AB.end(); it++)
		{
			if(CD.find(0 - (it->first)) != CD.end())
			{
				count += it->second * CD[0 - it->first];
			}
		}

		return count;
	}







};

int testcase(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D, int res, int casenum)
{
	Solution sol;
	
	if(sol.fourSumCount2(A, B, C, D) == res)
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
	vector<int> A, B, C, D;
	int res;
	int casenum;

	A = {1, 2};
	B = {-1, -1};
	C = {-1, 2};
	D = {0, 2};

	res = 2;
	casenum = 1;
	testcase(A, B, C, D, res, casenum);

	A = {-1, 1, 1, 1, -1};
	B = {0, -1, -1, 0, 1};
	C = {-1, -1, 1, -1, -1};
	D = {0, 1, 0, -1, -1};

	res = 132;
	casenum = 2;
	testcase(A, B, C, D, res, casenum);

	
}

