// future example
#include <iostream> // std::cout
#include <future> // std::async, std::future
#include <chrono> // std::chrono::milliseconds
#include <vector>
#include <thread>
using namespace std;

bool print_hello(void)
{
	while(1){
		cout << "hello" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	return true;
}

bool print_world(void)
{
	while(1){
		cout << "world" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	return true;
}

int main()
{
	// call function asynchronously:
	std::future<bool> fut1 = std::async(std::launch::async, print_hello);
	std::future<bool> fut2 = std::async(std::launch::async, print_world);

	fut1.wait();
	fut2.wait();

	return 0;
}

