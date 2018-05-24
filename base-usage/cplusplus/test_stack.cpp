#include <iostream> // std::cout, std::endl
#include <vector> // std::vector
#include <functional> // std::ref

int trap(std::vector<int>& v, int i)
{
	v.push_back(i);
	std::cout << i << std::endl;
	trap(v, ++i);
	return i;
}

int main()
{
	std::vector<int> v;
	trap(std::ref(v), 0);
}

