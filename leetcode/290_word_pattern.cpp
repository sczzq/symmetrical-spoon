/*************************************************************************
	> File Name: 290_word_pattern.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 03 May 2017 01:27:15 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	bool wordPattern(string pattern, string str){
		map<char, string> ps;
		map<string, char> rps;
		vector<string> words;
		getWords(words, str);
		cout << pattern << '\n';
		for(auto& s : words)
			cout << "\"" << s << "\",";
		cout << "\n";

		if(pattern.length() != words.size())
			return false;
		for(int i=0; i<pattern.length(); i++){
			char c = pattern.at(i);
			auto it = ps.find(c);
			if(it != ps.end()){
				if(ps[c] != words.at(i)){
					return false;
				}
			} else {
				ps[c] = words.at(i);
			}

			auto word = words.at(i);
			auto itr = rps.find(word);
			if(itr != rps.end()){
				if(rps[word] != pattern.at(i)){
					return false;
				}
			} else {
				rps[word] = pattern.at(i);
			}
		}
		return true;
	}

	void getWords(vector<string>& words, const string& str){
		size_t cur = -1, last = 0;
		while(true){
			cur = str.find_first_of(" ", cur+1);
			if(cur != string::npos){
				words.push_back(str.substr(last, cur-last));
				last = cur+1;
			} else break;
		}
		if(last < str.length())
			words.push_back(str.substr(last, str.length()-last));
	}
};

int main()
{
	string pattern { "abba" };
	string str { "dog cat cat dog" };
	Solution s;

	string pattern2 {"ab" };
	string str2 {"dog"};

	cout << s.wordPattern(pattern, str) << "\n";
	cout << s.wordPattern(pattern2, str2) << "\n";

	string str3{"dog cat cat fish"};
	cout << s.wordPattern(pattern, str3) << "\n";

	string str4{"dog dog dog dog" };
	cout << s.wordPattern(pattern, str4) << "\n";

}
