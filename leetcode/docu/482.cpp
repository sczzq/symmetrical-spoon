#include "cpp_header.h"


class Solution {
public:
    string licenseKeyFormatting2(string S, int K) {
        string res;

		if(S.length() <= K)
		{
			for(int i = 0; i < S.length(); i++)
			{
				char c = S[i];
                if(c >= 'a' && c <= 'z')
                    c = c - 'a' + 'A';
                else if(c >= '0' && c <= '9')
                    c = c;
                else if(c >= 'A' && c <= 'Z')
                    c = c;
                else if(c == '-')
                    continue;
                res += string{c};
			}
			return res;
		}

        for(int i = S.length() - 1, j = 0; i >= 0; i--)
        {
            char c = S[i];
            if(c >= 'a' && c <= 'z')
            {
                c = c - 'a' + 'A';
                res = string{c} + res;
            }
            else if(c >= 'A' && c <= 'Z')
            {
                res = string{c} + res;
            }
			else if(c >= '0' && c <= '9')
            {
                res = string{c} + res;
            }
            else if(c == '-')
            {
                continue;
            }

            if( (++j) % K == 0)
            {
                res = string{'-'} + res;
            }
        }
        if( res[0] == '-')
            res = res.substr(1);

        return res;
    }


    string licenseKeyFormatting(string S, int K) {
		vector<char> vres;
		for(int i = 0; i < S.length(); i++)
		{
			if((S[i] >= '0' && S[i] <= '9')
			   || (S[i] >= 'A' && S[i] <= 'Z'))
				vres.push_back(S[i]);
			else if(S[i] >= 'a' && S[i] <= 'z')
				vres.push_back(S[i] - 'a' + 'A');
		}

		string res;
		int first = vres.size() % K;

		for(int i = 0; i < first; i++)
			res += vres[i];

		for(int i = first; i < vres.size(); i+=K)
		{
			res += '-';
			for(int j = i; j < i+K; j++)
			{
				res += vres[j];
			}
		}
		if(first == 0)
			res.erase(res.begin());

		return res;
	}
};


int main()
{
	string S;
	int K;
	string res;
	int casenum;

	S = "5F3Z-2e-9-w";
	K = 4;
	res = "5F3Z-2E9W";
	casenum = 1;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "a";
	K = 1;
	res = "A";
	casenum = 2;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "aa";
	K = 1;
	res = "A-A";
	casenum = 3;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "aa-";
	K = 3;
	res = "AA";
	casenum = 4;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "---aa-";
	K = 3;
	res = "AA";
	casenum = 5;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);


	S = "--1334-aa-";
	K = 3;
	res = "133-4AA";
	casenum = 6;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "--1334-aa-";
	K = 2;
	res = "13-34-AA";
	casenum = 7;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "--134-aa-";
	K = 2;
	res = "1-34-AA";
	casenum = 8;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "134aa-";
	K = 2;
	res = "1-34-AA";
	casenum = 9;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "134aa-asdf---ccvad-asf--asd-f-asdf-sa-f-sdfasdffbbb-b--b-na-dfas-dfas-f-s-afdsf-fsdaa";
	K = 3;
	res = "134-AAA-SDF-CCV-ADA-SFA-SDF-ASD-FSA-FSD-FAS-DFF-BBB-BBN-ADF-ASD-FAS-FSA-FDS-FFS-DAA";
	casenum = 10;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

	S = "134aa-asdf---ccvad-asf--asd-f-asdf-sa-f-sdfasdffbbb-b--b-na-dfas-dfas-f-s-afdsf-fsda";
	K = 3;
	res = "13-4AA-ASD-FCC-VAD-ASF-ASD-FAS-DFS-AFS-DFA-SDF-FBB-BBB-NAD-FAS-DFA-SFS-AFD-SFF-SDA";
	casenum = 11;
	TESTCASE_p2(licenseKeyFormatting, S, K, res, casenum);

}

