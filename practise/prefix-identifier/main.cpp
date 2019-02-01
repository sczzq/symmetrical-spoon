#include "multiroottree.h"

int main()
{
	MultiRootTree tree;

	vector<string> vs;
	vs.push_back("hello");
	vs.push_back("hi");
	vs.push_back("word");
	vs.push_back("world");

	tree.Push(vs);

	vector<string> rvs = tree.Strings();

	cout << "original strings:\n";
	for (auto s : rvs)
	{
		cout << s << endl;
	}

	cout << "all uniq prefix:\n";
	vector<string> svs = tree.GetIdentifiers();
	for (auto s : svs)
	{
		cout << s << endl;
	}

	{
		Node n1('a');
		Node n2('a');
		Node n3('b');

		if (n1 == n2)
			cout << "n1 equals to n2\n";
		else
			cout << "n1 not equals to n2\n";
	}

	return 0;
}

