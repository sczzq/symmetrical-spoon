#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	std::vector<int> vi{2, 3, 222, 11};
	for(auto i : vi)
		std::cout << i << "\n";
	std::stack<std::vector<int>> vsi;
	vsi.push(vi);

	std::vector<int> vi2{3,4,5};
	vi.insert(vi.end(), vi2.begin(), vi2.end());

	std::cout << "-----------------\n";

	for(auto i : vi)
		std::cout << i << "\n";

	std::cout << "-----------------\n";
	cout << *vi.begin() << "\n";
	cout << *vi.rbegin() << "\n";

}
