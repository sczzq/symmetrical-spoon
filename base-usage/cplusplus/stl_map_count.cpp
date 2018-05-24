// map::count
#include <iostream>
#include <map>

int main()
{
	std::map<char, int> mymap;
	char c;

	mymap['a'] = 101;
	mymap['d'] = 202;
	mymap['c'] = 303;
	mymap['f'] = 303;

	for(c='a'; c<'h'; c++){
		std::cout << c;
		if(mymap.count(c) > 0)
			std::cout << " is an element of mymap.\n";
		else 
			std::cout << " is not na element of mymap\n";
	}

	return 0;
}
