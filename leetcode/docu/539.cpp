#include "cpp_header.h"

class Solution {
public:
	int findMinDifference(vector<string>& timePoints)
	{
		vector<int> minutes;

		for(auto & s : timePoints)
		{
			minutes.push_back(toMinute(s));
		}

		for(auto x : minutes)
		{
			cout << x << "  ";
		}
		cout << "\n";

		sort(minutes.begin(), minutes.end());

		int res = INT_MAX;
		for(int i = 0; i < minutes.size() - 1; i++)
		{
			if(res > (minutes[i+1] - minutes[i]))
			{
				res = minutes[i+1] - minutes[i];
				if(res == 0)
				{
					break;
				}
			}
		}
		if(res > (24*60 + minutes.front() - minutes.back()))
		{
			res = 24*60 + minutes.front() - minutes.back();
		}

		return res;
	}

	int toMinute(const string & str)
	{
		int res = 0;
		res += (str[0] - '0');
		res *= 10;

		res += (str[1] - '0');
		res *= 60;

		res += ((str[3] - '0') * 10);
		res += (str[4] - '0');

		return res;
	}
};

int testcase(vector<string> timePoints, int res, int casenum)
{
	Solution sol;
	if(sol.findMinDifference(timePoints) == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
	}

	return 0;
}

int main()
{

	vector<string> timePoints;
	int res;
	int casenum;

	timePoints = {"23:59", "00:00", "00:01"};
	res = 1;
	casenum = 1;
	testcase(timePoints, res, casenum);

	timePoints = {"23:59", "00:10", "00:20", "01:30", "02:00"};
	res = 10;
	casenum = 2;
	testcase(timePoints, res, casenum);

}

