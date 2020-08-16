#include <map>
#include <iostream>

using namespace std;

int main()
{
	multimap<int, int> ms;

	ms.emplace(7,7);
	ms.emplace(7,10);
	ms.emplace(6,10);
	ms.emplace(4,10);
	ms.emplace(7,10);

	for(auto x = ms.rbegin(); x != ms.rend(); x++)
	{
		cout << x->first << ":" << x->second << "\n";
	}


	cout << ms.size() << "\n";
}




