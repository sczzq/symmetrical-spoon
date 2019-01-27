#include "factory.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main()
{
	factory fact;

	string conf{"config.conf"};

	ifstream input(conf);

	vector<string> v;
	vector<base_class *> cn;

    for (string s ; getline(input, s); ) {
        v.push_back(s);
    }

	for (const auto &s : v)
	{
		base_class *base = fact.GetImplementation(s);
		if (!base)
		{
			cout << "no " << s << endl;
		}
		else
		{
			cn.push_back(base);
		}
	}

	for (auto &c : cn)
	{
		cout << c->GetClassName() << endl;
	}

	for (auto c : cn)
	{
		delete c;
	}

	cn.clear();

	return 0;
}

