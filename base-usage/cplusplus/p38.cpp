#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

void user(list<pair<string, double>>& lst)
{
	auto p = lst.begin();
	string s {"Dendark"};
	while(p!=lst.end() && p->first!=s)
		++p; // do nothing
	s = {"England"};
	p = lst.emplace(p, s, 7.5);
	s = {"Franch"};
	p = lst.insert(p,make_pair(s, 9.8));
//	p = lst.insert(p, pair<string, double>>{"Greece", 3.14});
}

int main()
{

	list<pair<string, double>> lst;
	string s{"Chinese"};
	lst.insert(lst.begin(), make_pair(s, 100.0));
	s = {"American"};
	lst.insert(lst.begin(), make_pair(s, 16.0));
	s = {"Russian"};
	lst.insert(lst.begin(), make_pair(s, 66.0));
	s = {"Dendark"};
	lst.insert(lst.begin(), make_pair(s, 6.0));

	for(auto& x : lst)
		cout << x.first << ", " << x.second << "; ";
	cout << endl;

	user(lst);

	for(auto& x : lst)
		cout << x.first << ", " << x.second << "; ";
	cout << endl;

}
