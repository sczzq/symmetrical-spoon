/*************************************************************************
	> File Name: findMaxForm.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 10:11:15 PM CST
 ************************************************************************/

#include <iostream> // cout, endl
#include <string> // string
#include <utility>  // pair, make_pair
#include <queue> // queue
#include <algorithm> // find
#include <vector> // vector
using namespace std;

class Solution{
private:
	class pNode{
	public:
		pNode(int number, vector<pair<int, int>> pair, int m, int n){
			numbers = number;
			pairs = pair;
			zeros = m;
			ones = n;
		}
		pNode(const pNode& p){
			numbers = p.numbers;
			pairs = p.pairs;
			zeros = p.zeros;
			ones = p.ones;
		}
		vector<pair<int, int>> pairs;
		int numbers;
		int zeros;
		int ones;
	};
public:
	int findMaxForm(vector<string>& strs, int m, int n){
		queue<pNode> qm;
		vector<pair<int, int>> pairs;
		int number;
		genePairs(pairs, strs);
		geneNode(qm, pairs, 0, m, n);
		while(!qm.empty()){
			pNode p(qm.front());
			number = p.numbers;
			qm.pop();
			geneNode(qm, p.pairs, p.numbers, p.zeros, p.ones);
		}
		return number;
	}

private:
	bool genePairs(vector<pair<int, int>>& pairs, vector<string>& strs){
		for(string& str : strs)
			pairs.push_back(getIndex(str));
		return true;
	}

	bool geneNode(queue<pNode>& qm, vector<pair<int, int>>& pairs, int number, int m, int n){
		for(pair<int, int>& pai : pairs){
			if(isRep(pai, m, n)){
				vector<pair<int, int>> newpairs(pairs);
				newpairs.erase(find(newpairs.begin(), newpairs.end(), pai));
				pNode p(number+1, newpairs, m - pai.first, n - pai.second);
				qm.push(p);
			}
		}
		return true;
	}

	bool isRep(string& str, int m, int n){
		std::pair<int, int> p = getIndex(str);
		if(p.first <= m && p.second <= n)
			return true;
		else
			return false;
	}

	bool isRep(pair<int, int> pai, int m, int n){
		if(pai.first <= m && pai.second <= n)
			return true;
		else
			return false;
	}

	pair<int, int> getIndex(string& str){
		std::pair<int, int> p;
		int os = 0, // ones
			zs = 0; // zeros
		for(char x : str)
			if(x == '0')
				zs++;
			else
				os++;
		return p = std::make_pair(zs, os);
	}
};

int main()
{
	vector<string> strs1{"10", "0", "1"};
	int m = 1, n = 1;
	Solution s;
	cout << s.findMaxForm(strs1, m, n) << endl;

	vector<string> strs2{"10", "0001", "111001", "1", "0"};
	m = 5, n = 3;

	cout << s.findMaxForm(strs2, m, n) << endl;

	vector<string> strs3{"00", "000"};
	m = 1, n = 10;

	cout << s.findMaxForm(strs3, m, n) << endl;

	return 0;
}
