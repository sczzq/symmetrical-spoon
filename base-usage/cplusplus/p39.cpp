#include <iostream>
#include <vector>
#include <string>
using namespace std;

void use()
{
	vector<char> chars;
	constexpr int max = 20000;
	chars.reserve(max);
	vector<char*> words;

	bool in_word = false;
	for(char c; cin.get(c); ){
		if(isalpha(c)){
			if(!in_word){
				in_word = true;
				chars.push_back(0);
				chars.push_back(c);
				words.push_back(&chars.back());
			} else {
				chars.push_back(c);
			}
		} else {
			in_word = false;
		}
	}

	if(in_word)
		chars.push_back(0);
	if(max < chars.size()){
		;
	}
	for(auto& x : chars)
		cout << x << " ";
	cout << endl;
	for(auto& w : words)
		cout << w << " ";
	cout << endl;
	chars.shrink_to_fit();
}

int main()
{
	use();
}

