#include <string> // string
#include <iostream>
#include <utility>  // pair, make_pair
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
        vector<pNode> vp;
		vector<pair<int, int>> pairs;
		int number = 0;
		vector<int> index;
		vector<int> valid;

		genePairs(pairs, index, strs);
		for(int i = 0; i < pairs.size(); i++){
			pair<int, int>& p = pairs[i];
			if(p.first <= m && p.second <= n){
				valid.push_back(i);
			}
		}
		if(!valid.empty())
			number = 1;
		pNode pnode(number, valid, m, n);
//		cout << "first: " << p.numbers << ", " << p.zeros << "," << p.ones << ";;" << endl;
//		geneNode(vp, p, pairs);
		vp.push_back(pnode);

		cout << "vector pnode size: " << vp.size() << endl;
		while(!vp.empty()){
			pNode p(vp[0]);
			number = p.numbers;
			cout << "pNode: [ number=" << p.numbers << ", valid={";
			for(int va:p.valid)
				cout << va << ",";
			cout << "}, zeros=" << p.zeros << ", ones=" << p.ones << " ]" <<endl;
//			cout << "while: " << number << endl;
//			cout << "while: " << p.numbers << endl;
			vp.erase(vp.begin());
			bool b = geneNode(vp, p, pairs);
			cout << "in while, vector pnode size: " << vp.size() << ", number: " << number << endl;
//			cout << "valid empty: " <<  b << endl;
//			if(b && vp.size() == 1)
//				break;
		}
		return number;
    }

private:
	bool genePairs(vector<pair<int, int>>& pairs, vector<int>& valid, vector<string>& strs){
		int i = 0;
		cout << "init valid: " ;
		for(string& str : strs){
			pair<int, int> p = getPair(str);
			pairs.push_back(p);
			cout << i << ",";
			valid.push_back(i++);
		}
		cout << endl;
		return true;
	}

	bool geneNode(vector<pNode>& vp, pNode& p, vector<pair<int, int>>& pairs){
		vector<int>& valid = p.valid;
		cout << "valid: ";
		for(int va : valid){
			cout << va << ", ";
			if(!isIn(va, vp) && (isRep(pairs[va], p.zeros, p.ones))){
				vector<int> newvalid;
				for(int vv : valid){
					if(vv != va && !isIn(vv, vp)){
						int number = p.numbers, zeros = p.zeros, ones = p.ones; 
						if(isRep(pairs[vv], zeros - pairs[va].first, ones - pairs[va].second))
							newvalid.push_back(vv);
					}
				}
				cout << "newvalid: { ";
				for(int vvv : newvalid)
					cout << vvv << ", ";
				cout << "}" << endl;
				if(!newvalid.empty()){
					int number = p.numbers, zeros = p.zeros, ones = p.ones; 
					pNode p(number + 1, newvalid, zeros - pairs[va].first, ones - pairs[va].second);
					vp.push_back(p);
				}
			}
		}
		cout << endl;
		if(valid.empty())
			return false;
		return true;
	}

	bool isIn(int va, vector<pNode>& vp)
	{
		for(pNode& p : vp){
			for(int v : p.valid){
//				cout << "va: " << va << ", v: " << v << endl;
				if(va == v)
					return true;
			}
		}
		return false;
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

	vector<string> strs11{"10", "0", "1"};
	m = 1, n = 1;
	number = s.findMaxForm(strs11, m, n);
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
	number = s.findMaxForm(strs3, m, n);
	cout << number << endl;

	vector<string> strs4{"10","0001","111001","1","0"};
	m = 3, n = 4;
	number = s.findMaxForm(strs4, m, n);
	cout << number << endl;

	vector<string> strs5{"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
	m = 9, n = 80;
	number = s.findMaxForm(strs5, m, n);
	cout << number << endl;

	return 0;
}
