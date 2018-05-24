#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Nocase{
public:
	bool operator()(const string&, const string&) const;
};

bool Nocase::operator()(const string& x, const string& y) const
	// 若x字典序上小于y，则返回true，不考虑大小写.
{
	auto p = x.begin();
	auto q = y.begin();

	while(p!=x.end() && q!=y.end() && toupper(*p)==toupper(*q)){
		++p;
		++q;
	}
	if(p == x.end()) return q != y.end();
	if(q == y.end()) return false;
	return toupper(*p) < toupper(*q);
}

struct Cstring_less{
	bool operator()(const char* p, const char* q) const { return strcmp(p, q) < 0;}
}

int main()
{
	vector<string> fruits{"apple", "pear", "Apple", "Pear", "lemon"};
	sort(fruits.begin(), fruits.end(), Nocase());
	for(auto& fruit : fruits)
		cout << fruit << "  ";
	cout << endl;

	sort(fruits.begin(), fruits.end());
	for(auto& fruit : fruits)
		cout << fruit << "  ";
	cout << endl;
}

