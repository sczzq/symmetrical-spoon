// stack::push/pop
#include <iostream>
#include <stack>

int main()
{
	std::stack<int> mystack;

	for(int i=0; i<5; ++i) mystack.push(i);
	std::cout << "poping out elements...";

	while(!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << "\n";

	return 0;
}
