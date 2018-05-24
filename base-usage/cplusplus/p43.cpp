#include <iostream>
#include <list>
#include <string>

using namespace std;
void use()
{
	list<int> lst{2,3,2,3,5};
	for(auto& x : lst)
		cout << x << " ";
	cout << endl;

	lst.remove(3);
	for(auto& x : lst)
		cout << x << " ";
	cout << endl;

	lst.unique();
	for(auto& x : lst)
		cout << x << " ";
	cout << endl;

	cout << lst.size() << endl;
}

void use2()
{
	list<int> lst1{1,2,3};
	list<int> lst2{4,5,6};

	auto p = lst1.begin();
	cout << *p << endl;
	++p;
	cout << "p" << ": " << *p << endl;

	auto q = lst2.begin();
	cout << *q << endl;
	++q;
	cout << "q" << ": " << *q << endl;

	lst1.splice(p, lst2);
	for(auto& x : lst1)
		cout << x << " ";
	cout << endl;
	for(auto& x : lst2)
		cout << x << " ";
	cout << endl;
	cout << "p" << ": " << *p << endl;
	cout << "q" << ": " << *q << endl;
}

int main()
{
	use2();
}
