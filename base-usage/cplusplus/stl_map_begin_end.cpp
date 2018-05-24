// map::begin/end
#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<char, int> mymap;
	mymap['d'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	mymap['f'] = 700;
	mymap['i'] = 800;
	mymap['g'] = 400;

	for(std::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::map<std::string, int> mymap2;
	if(mymap2.begin() == mymap2.end())
		std::cout << "mymap2 is empty" << std::endl;
	for(std::map<std::string, int>::iterator it=mymap2.begin(); it!=mymap2.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::map<char, int> mymap_copy;
	mymap_copy = mymap;
	for(std::map<char, int>::iterator it=mymap_copy.begin(); it!=mymap_copy.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}
