#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "abcd";
	for(int i = 0; i < 20; i++){
		cout << s;
		for(int j = 0; j < s.length(); j++)
			cout << '\b';
//		cout << '\v';
//		cout << '\t';
//		cout << '\n';
	}
}
