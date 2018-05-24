// stack::swap
#include <iostream>
#include <stack>

int main()
{
	std::stack<int> foo, bar;
	foo.push(10); foo.push(20); foo.push(30);
	bar.push(101); bar.push(202);

	std::cout << "size of foo before swap: " << foo.size() << "\n";
	std::cout << "size of bar before swap: " << bar.size() << "\n";

	foo.swap(bar);

	std::cout << "size of foo after swap: " << foo.size() << "\n";
	std::cout << "size of bar after swap: " << bar.size() << "\n";
}
