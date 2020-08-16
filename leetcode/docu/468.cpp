#include "cpp_header.h"

class Solution {
public:
	string validIPAddress(string IP)
	{
		int dot_nums = count(IP.begin(), IP.end(), '.');
		if(dot_nums == 3)
			if(consider_v4(IP))
				return "IPv4";

		int colon_nums = count(IP.begin(), IP.end(), ':');
		if(colon_nums == 7)
			if(consider_v6(IP))
				return "IPv6";

		return "Neither";
	}

	bool consider_v6(string & s)
	{
		if(s.length() > 39)
			return false;

		string ns;

		for(auto x : s)
		{
			if(x >= 'A' && x <= 'F')
				ns += ('Z' - 'A' + 'a');
			else if(x >= '0' && x <= '9')
				ns += x;
			else if(x == ':')
				ns += x;
			else if(x >= 'a' && x <= 'f')
				ns += x;
		}

		if(ns.length() != s.length())
			return false;

		int i = 0, j = 0;
		int sep = 0;
		while(j < ns.length())
		{
			while(j < ns.length() && ns[j] != ':')
				j++;
			if(i == j)
				return false;
			if(j - i > 4)
				return false;

			j++;
			i = j;
			sep++;
		}

		if(sep != 8)
			return false;

		return true;
	}

	bool consider_v4(string &s)
	{
		if(s[0] == '0') return false;

		if(s.length() > 15) return false;

		int i = 0, j = 0;
		int sep = 0;
		while(j < s.length())
		{
			while(j < s.length() && s[j] != '.')
				j++;
			if(i == j)
				return false;
			if(j - i > 3)
				return false;
			
			if(check_v4_num(s, i, j) == false)
				return false;
			i++;
			j++;
			sep++;
		}

		if(sep != 4)
			return false;

		return true;
	}

	bool check_v4_num(string& s, int & i, int & j)
	{
		if(j - i == 3)
		{
			if(s[i] == '1' && s[i+1] >= '0' && s[i+1] <= '9'
					&& s[i+2] >= '0' && s[i+2] <= '9')
				i = j;
			else if(s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '4'
					&& s[i+2] >= '0' && s[i+2] <= '9')
				i = j;
			else if(s[i] == '2' && s[i+1] == '5'
					&& s[i+2] >= '0' && s[i+2] <= '5')
				i = j;
		}
		else if(j - i == 2)
		{
			if(s[i] >= '1' && s[i] <= '9' 
					&& s[i+1] >= '0' && s[i+1] <= '9')
				i = j;
		}
		else if(j - i == 1)
		{
			if(s[i] >= '0' && s[i] <= '9')
				i = j;
		}

		if(i != j)
			return false;

		return true;
	}

};

int testcase(string IP, string res, int casenum)
{
	Solution sol;

	if(sol.validIPAddress(IP) == res)
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
	string IP;
	string res;
	int casenum;

	IP = "0.0.0.0";
	res = "Neither";
	casenum = 1;
	testcase(IP, res, casenum);

	IP = "1.0.0.0";
	res = "IPv4";
	casenum = 2;
	testcase(IP, res, casenum);

	IP = "1.01.0.0";
	res = "Neither";
	casenum = 3;
	testcase(IP, res, casenum);

	IP = "1.01.0.0.";
	res = "Neither";
	casenum = 4;
	testcase(IP, res, casenum);

	IP = ".1.01.0";
	res = "Neither";
	casenum = 5;
	testcase(IP, res, casenum);

	IP = "256.256.256.256";
	res = "Neither";
	casenum = 6;
	testcase(IP, res, casenum);

	IP = "254.254.254.256";
	res = "Neither";
	casenum = 7;
	testcase(IP, res, casenum);

	IP = "254.254.256.254";
	res = "Neither";
	casenum = 8;
	testcase(IP, res, casenum);

	IP = "254.256.254.254";
	res = "Neither";
	casenum = 9;
	testcase(IP, res, casenum);

	IP = "256.254.254.254";
	res = "Neither";
	casenum = 10;
	testcase(IP, res, casenum);

	IP = "176.123.23.2";
	res = "IPv4";
	casenum = 11;
	testcase(IP, res, casenum);

	IP = "76.223.23.0";
	res = "IPv4";
	casenum = 12;
	testcase(IP, res, casenum);


	IP = "76:223:23:0:12ff:a123:123:a";
	res = "IPv6";
	casenum = 13;
	testcase(IP, res, casenum);

	IP = "00076:223:23:0:12ff:a123:123:a";
	res = "Neither";
	casenum = 14;
	testcase(IP, res, casenum);

	IP = "0076:00223:23:0:12ff:a123:123:a";
	res = "Neither";
	casenum = 15;
	testcase(IP, res, casenum);

	IP = "0076:0223:23::12ff:a123:123:a";
	res = "Neither";
	casenum = 16;
	testcase(IP, res, casenum);

	IP = "0076:0223:23:0000:12ff:a123:123:a";
	res = "IPv6";
	casenum = 17;
	testcase(IP, res, casenum);

	IP = "0076:0223:23:0000:12ff:a123:123:0000";
	res = "IPv6";
	casenum = 18;
	testcase(IP, res, casenum);

	IP = ":0076:0223:23:0000:12ff:a123:123";
	res = "Neither";
	casenum = 19;
	testcase(IP, res, casenum);

	IP = "0076:0223:23:0000:12ff:a123:123:FFFf";
	res = "IPv6";
	casenum = 20;
	testcase(IP, res, casenum);


	IP = "1.0.1.";
	res = "Neither";
	casenum = 21;
	testcase(IP, res, casenum);

	IP = "0076:0223:23:0000:12ff:a123:123:";
	res = "Neither";
	casenum = 22;
	testcase(IP, res, casenum);

	IP = "0076:0223:23:0000:12ff:a123::";
	res = "Neither";
	casenum = 23;
	testcase(IP, res, casenum);

	IP = "0076:0G23:23:0000:12ff:a123:0:0";
	res = "Neither";
	casenum = 24;
	testcase(IP, res, casenum);

	IP = "219.219.219.219";
	res = "IPv4";
	casenum = 25;
	testcase(IP, res, casenum);


}




