/*************************************************************************
    > File Name: allPossible.cpp
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年08月19日 星期日 17时11分05秒
 ************************************************************************/

#include "header.h"
#include<iostream>
#include<vector>
using namespace std;

vector<int> depthFirst(vector<vector<int>> &sets, int index);

int findMax(vector<int> &v)
{
	if (v.size() < 1) {
		return 0;
	}
	int max = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

int findMin(vector<int> &v)
{
	if (v.size() < 1) {
		return 0;
	}
	int min = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (min > v[i]) {
			min = v[i];
		}
	}
	return min;
}

int findClosest(vector<int> &v, int k)
{
	if (v.size() < 1) {
		return -1;
	}
	int minus = abs(v[0] - k);
	int kk = v[0];

	if (kk == k) {
		return -1;
	}
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == k) {
			continue;
		}
		int mm = abs(v[i] - k);
		if (minus > mm) {
			minus = mm;
			kk = v[i];
		}
	}
	return kk;
}

int depthFirst(vector<vector<int>> &sets, int index, vector<vector<int>> &all, vector<int> res)
{
	if (index >= sets.size()){
		return 0;
	}
	for (auto c : sets[index]) {
		vector<int> sha = res;
		sha.push_back(c);
		if (index+1 == sets.size()) {
			cout << "depthFirst: ";
			showVector(sha);
			all.push_back(sha);
		} else {
			depthFirst(sets, index+1, all, sha);
		}
	}
	return 0;
}

int findEnclosed(vector<int> &v, int first, int second)
{
	if (v.size() < 1) {
		return -1;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > first && v[i] < second) {
			return v[i];
		}
	}
	return -1;
}

int depthFirst2(vector<vector<int>> &sets, int index, vector<vector<int>> &all, vector<int> res)
{
	if (index >= sets.size()) {
		return 0;
	}
	vector<int> sha = res;
	if (sha.size() == 1){
		int kkc = findClosest(sets[index], min);
		if (kkc != -1)
			sha.push_back(kkc);
	}
	else {
		int max = findMax(sha);
		int min = findMin(sha);
		int enclosed = findEnclosed(sets[index], min, max);

		if (enclosed == -1){
			int kc = findClosest(sets[index], min);
			int kkc = findClosest(sets[index], max);
			if (kc != -1 && kkc != -1) {
				if (kc > kkc) {
					sha.push_back(kkc);
				} else {
					sha.push_back(kkc);
				}
			}
		}
	}

	if (index + 1 == sets.size()) {
		showVector(sha);
		all.push_back(sha);
	} else {
		depthFirst2(sets, index+1, all, sha);
	}

	return 0;
}

int allPossible2(vector<vector<int>> &sets, vector<vector<int>> &all)
{
	for (int index = 0; index < sets[0].size(); index++) {
		vector<int> res;
		res.push_back(sets[0][index]);
		depthFirst2(sets, 1, all, res);
	}
	return 0;
}

int allPossible(vector<vector<int>> &sets, vector<vector<int>> &all)
{
	for (int index = 0; index < sets[0].size(); index++) {
		vector<int> res;
		res.push_back(sets[0][index]);
		depthFirst(sets, 1, all, res);
	}
	return 0;
}

/*
int main()
{
	vector<vector<int>> sets = {
		{
			0,10
		}, {
			3,9
		}, {
			5,12
		}
	};

	vector<vector<int>> res;
	allPossible(sets, res);

	for(int i = 0; i < res.size(); i++)
		showVector(res[i]);
}
*/

