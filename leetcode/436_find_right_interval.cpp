/*************************************************************************
	> File Name: 436_find_right_interval.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 05 May 2017 04:00:59 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Definition for an interval
 */

struct Interval {
	int start;
	int end; 
	Interval(): start(0), end(0) { }
	Interval(int s, int e): start(s), end(e) { }
};

struct mLess{
	bool operator()(const Interval& lhs, const Interval& rhs)
	{ return lhs.end <= rhs.start;}
};

class Solution{
public:
	vector<int> findRightInterval(vector<Interval>& intervals){
		vector<int> vts(intervals.size(), -1);
		vector<Interval>& its = intervals;
//		map<Interval, int, mLess> mts (intervals.begin(), intervals.end()); 
		map<Interval, int, mLess> mts; 
		vector<map<Interval, int, mLess>> vmts;

		int number = 0;
		vmts.push_back(mts);
		bool isAllHas = true;
		for(int i=0; i<its.size(); i++){
			isAllHas = true;
			for(int vm=0; vm<vmts.size(); vm++){
				if(vmts[vm].find(its[i]) == vmts[vm].end()){
					isAllHas = false;
					mts[its[i]] = i;
				}
			}
			if(isAllHas){
				map<Interval, int, mLess> newmts; 
				newmts[its[i]] = i; 
				vmts.push_back(newmts);
			}
		}

		cout << "mts size: " << mts.size() << "\n";

		return vts;
	}

	bool getRight(vector<Interval>& its, vector<int>& vts){
		bool isHas = false;
		for(int i=0; i<its.size(); i++){
			for(int j=1; j<its.size(); j++){
				if(isRight(its[i], its[j])){
					vts[j] = minStartIndex(its, vts[j], i);
				} else if(isRight(its[j], its[i])){
					vts[i] = minStartIndex(its, vts[i], j);
				}
			}
		}
		return isHas;
	}

	int minStartIndex(vector<Interval>& its, int first, int second){
		if(its[first].start > its[second].start)
			return second;
		return first;
	}

	bool isRight(Interval& one, Interval& two){
		if(one.start >= two.end)
			return true;
		return false;
	}

	void show(vector<int>& v){
		for(auto i : v)
			cout << i << ", ";
		cout << "\n";
	}

};

void showIts(vector<Interval>& its){
	for(auto& it : its){
		cout << "[" << it.start << "," << it.end << "],";
	}
	cout << endl;
}

void show(vector<int>& v){
	for(auto i : v)
		cout << i << ", ";
	cout << "\n";
}

int main()
{
	vector<Interval> its {
		{1,2}
	};
	vector<int> right;
	Solution s;

	right = s.findRightInterval(its);
	showIts(its);
	show(right);

	its = {
		{3,4}, {2,3}, {1,2}
	};
	right = s.findRightInterval(its);
	showIts(its);
	show(right);

	its = {
		{1,4}, {2,3}, {3,4}
	};
	right = s.findRightInterval(its);
	showIts(its);
	show(right);

	its = {
		{3,4}, {2,3}, {1,2}
	};
	right = s.findRightInterval(its);
	showIts(its);
	show(right);

	its = {
		{3,4}, {1,2}, {2,3}
	};
	right = s.findRightInterval(its);
	showIts(its);
	show(right);

	its = {
		{30,40}, {10,20}, {21,31}, {20, 21}, {30,60}
	};
	right = s.findRightInterval(its);
	showIts(its);
	show(right);

}


