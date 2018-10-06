/*************************************************************************
    > File Name: minWindow.cpp
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年08月19日 星期日 16时33分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <climits>
#include "header.h"
#include "allPossible.cpp"
using namespace std;

/*
给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"

说明：

    如果 S 中不存这样的子串，则返回空字符串 ""。
    如果 S 中存在这样的子串，我们保证它是唯一的答案。

*/

string minWindow(string &s, string &t)
{
	string minwindow = "";

	if (t.length() > s.length()) {
		return minwindow;
	}

	if (t.length() == 1) {
		auto pos = s.find(t);
		if (pos != string::npos) {
			minwindow = s[pos];
		}
		return minwindow;
	}

	vector<vector<int>> sets;
	for (auto c : t) {
		vector<int> set;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == c) {
				set.push_back(i);
			}
		}
		showVector(set);
		if (set.size() > 0) {
			sets.push_back(set);
		}
	}
	if (sets.size() != t.length()) {
		return minwindow;
	}

	cout << "sets size: " << sets.size() << endl;
	cout << "--------------\n";

	vector<vector<int>> result;

	allPossible2(sets, result);

	cout << "result size: " << result.size() << endl;
	cout << "--------------\n";

	for (int i = 0; i < result.size(); i++) {
		sort(result[i].begin(), result[i]. end());
	}

	for (int i = 0; i < result.size(); i++) {
		auto &res = result[i];
		bool dup = false;
		for (int j = 0; j < res.size() - 1; j++) {
			if (res[j] == res[j+1]) {
				dup = true;
				break;
			}
		}
		if (dup) {
			result.erase(result.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < result.size() - 1; i++) {
		auto &res1 = result[i];
		auto &res2 = result[i+1];
		if (res1.size() == res2.size()) {
			bool issame = true;
			for (int j = 0; j < res1.size(); j++) {
				if (res1[j] != res2[j]) {
					issame = false;
				}
			}
			if (issame) {
				result.erase(result.begin() + i);
				i--;
			}
		}
	}

	cout << "--------------\n";

	vector<int> min_v;
	int min = INT_MAX;
	int g_greater = 0, g_least = 0;
	for (auto res : result) {
		showVector(res);
		int greater = INT_MIN, least = INT_MAX;
		greater = findMax(res);
		least = findMin(res);
		if (greater != least && min > greater - least) {
			min = greater - least;
			min_v = res;
			g_greater = greater;
			g_least = least;
		}
	}

	cout << g_least << ", " << g_greater << endl;
	for (int i = g_least; i <= g_greater && i < s.length(); i++) {
		minwindow += s[i];
	}
	return minwindow;
}

int main()
{
	string s = "ADOBECODEBANC", t = "ABC";

	cout << "s: " << s << ", t: " << t << endl;
	cout << minWindow(s, t) << endl;

	t = "AA";
	cout << "s: " << s << ", t: " << t << endl;
	cout << minWindow(s, t) << endl;

	s = "a", t = "a";
	cout << "s: " << s << ", t: " << t << endl;
	cout << minWindow(s, t) << endl;

	s = "a", t = "aa";
	cout << "s: " << s << ", t: " << t << endl;
	cout << minWindow(s, t) << endl;

	s = "aaaaa", t = "aaa";
	cout << "s: " << s << ", t: " << t << endl;
	cout << minWindow(s, t) << endl;

	s = "ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country";
	t = "ask_country";
	cout << "s: " << s << ", t: " << t << endl;
	cout << minWindow(s, t) << endl;

}
