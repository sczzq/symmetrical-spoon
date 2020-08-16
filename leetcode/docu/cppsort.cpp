#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::vector<int> v{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

	std::sort(v.begin(), v.end());

	for(auto x : v)
		cout << x << ' ';
	cout << '\n';


	v = {1};
	std::sort(v.begin(), v.end());

	for(auto x : v)
		cout << x << ' ';
	cout << '\n';



}

