#include <string> // string
#include <iostream>
#include <utility>  // pair, make_pair
#include <queue> // queue
#include <algorithm> // find
#include <vector> // vector
using namespace std;
class Solution {
private:
	class pNode{
	public:
		pNode(int number, vector<int>& valid, int m, int n){
			this->numbers = number;
			this->zeros = m;
			this->ones = n;
			this->valid = valid;
		}
		pNode(const pNode& p){
			this->numbers = p.numbers;
			this->zeros = p.zeros;
			this->ones = p.ones;
			this->valid = p.valid;
		}
		int numbers;
		int zeros;
		int ones;
		vector<int> valid;
	};

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
		cout << "[";
		for(string& s : strs){
			cout << "\"" << s << "\" ";
		}
		cout << "]" << endl;
        queue<pNode> qm;
		vector<pair<int, int>> pairs;
		int number = 0;
		vector<int> valid;

		genePairs(pairs, valid, strs);
		pNode p(0, valid, m, n);
		cout << "first: " << p.numbers << ", " << p.zeros << "," << p.ones << ";;" << endl;
		geneNode(qm, p, pairs);

		while(!qm.empty()){
			pNode p(qm.front());
			number = p.numbers;
			cout << "while: " << number << endl;
//			cout << "while: " << p.numbers << endl;
			qm.pop();
			bool b = geneNode(qm, p, pairs);
			cout << "valid empty: " <<  b << endl;
			if(b && qm.size() == 1)
				break;
		}
		return number;
    }

private:
	bool genePairs(vector<pair<int, int>>& pairs, vector<int>& valid, vector<string>& strs){
		int i = 0;
		for(string& str : strs){
			pair<int, int> p = getPair(str);
			pairs.push_back(p);
//			cout << i << "---" << str << ": " << p.first << "," << p.second << endl;
			valid.push_back(i++);
		}
		return true;
	}

	bool geneNode(queue<pNode>& qm, pNode& p, vector<pair<int, int>>& pairs){
		vector<int>& valid = p.valid;
		for(int va : valid){
			if(isRep(pairs[va], p.zeros, p.ones)){
				vector<int> newvalid = valid;
				newvalid.erase(find(newvalid.begin(), newvalid.end(), va));
				int number = p.numbers, zeros = p.zeros, ones = p.ones; 
				/*
				 * donot use number = p.numbers, zeros = p.zeros, ones = p.ones; and use
				 *   pNode p(p.numbers + 1, newvalid, p.zeros - pairs[va].first, p.ones - pairs[va].second);
				 * than somethings wrong, may be its reference cannot do that plus or others.
				 */
//				cout << "geneNode: " << number + 1 << ",, " << zeros - pairs[va].first << ", " << ones - pairs[va].second << ";;" << endl;
				pNode p(number + 1, newvalid, zeros - pairs[va].first, ones - pairs[va].second);
				qm.push(p);
			}
		}
		if(valid.empty())
			return false;
		return true;
	}

	bool isRep(pair<int, int>& pai, int zeros, int ones){
		if(pai.first <= zeros && pai.second <= ones)
			return true;
		else
			return false;
	}

	pair<int, int> getPair(string& str){
		int zeros = 0, ones = 0;
		pair<int, int> p;
		for(char x : str){
			if(x == '0')
				zeros++; 
			else if (x == '1')
				ones++;
		}
		return p = std::make_pair(zeros, ones);
	}
};

int main(){
	vector<string> strs{"00", "000"};
	int m = 1, n = 10;
	int number = 0;

	Solution s;
	number = s.findMaxForm(strs, m, n);
	cout << number << endl;

	vector<string> strs1{"10", "0", "1", "0", "1", "0", "1", "11", "0", "1"};
	m = 10, n = 10;
	number = s.findMaxForm(strs1, m, n);
	cout << number << endl;

	vector<string> strs2{"10", "0001", "111001", "1", "0"};
	m = 5, n = 3;
	number = s.findMaxForm(strs2, m, n);
	cout << number << endl;

	vector<string> strs3{"0","1101","01","00111","1","10010","0","0","00","1","11","0011"};
	m = 63, n = 36;
//	number = s.findMaxForm(strs3, m, n);
	cout << number << endl;

	return 0;
}
