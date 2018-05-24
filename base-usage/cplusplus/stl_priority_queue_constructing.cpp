// constructing priority queues
#include <iostream> // std::cout
#include <queue>  // std::priority_queue
#include <vector> // std::vector
#include <functional> // std::greater

class mycomparison
{
	bool reverse;
public:
	mycomparison(const bool& revparam=false)
	{ reverse = revparam; }
	bool operator()(const int& lhs, const int& rhs) const{
		if(reverse) return (lhs>rhs);
		else return (lhs<rhs);
	}
};

int main()
{
	int myints[] = {10, 60, 50, 20};

	std::priority_queue<int> first;
	while(!first.empty()){
		std::cout << first.top() << " ";
		first.pop();
	}
	std::cout << '\n';
	std::priority_queue<int> second(myints, myints+4);
	while(!second.empty()){
		std::cout << second.top() << " ";
		second.pop();
	}
	std::cout << '\n';
	std::priority_queue<int, std::vector<int>, std::greater<int>> third (myints, myints+4);
	while(!third.empty()){
		std::cout << third.top() << " ";
		third.pop();
	}
	std::cout << '\n';

	typedef std::priority_queue<int, std::vector<int>, mycomparison> mypq_type;

	mypq_type fourth;
	while(!fourth.empty()){
		std::cout << fourth.top() << " ";
		fourth.pop();
	}
	std::cout << '\n';
	mypq_type fifth(mycomparison(true));
	while(!fifth.empty()){
		std::cout << fifth.top() << " ";
		fifth.pop();
	}
	std::cout << '\n';

	return 0;
}
