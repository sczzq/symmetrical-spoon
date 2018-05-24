// future example
#include <iostream> // std::cout
#include <future> // std::async, std::future
#include <chrono> // std::chrono::milliseconds
#include <vector>

// a non-optimized way of checking for prime numbers:
bool is_prime(int x)
{
	std::vector<int> primes {2,3,5,7,11,13,17,19,23,29,31};
	primes.reserve(x/4);
	for(int i = 33; i <= x; ++i){
		int j = 0;
		for(; j!=primes.size(); ++j)
			if( i % primes[j] == 0)
				break;
		if(j == primes.size()){
			primes.push_back(i);
		}
	}
	if( primes[primes.size()-1] == x) return true;

	return false;
}

int main()
{
	int number = 444443;
	// call function asynchronously:
	std::future<bool> fut = std::async(std::launch::async, is_prime, number);

	// do something while waiting for function to set future:
	std::cout << "checking ,please waiting";
	std::chrono::milliseconds span (100);
	while(fut.wait_for(span) == std::future_status::timeout)
		std::cout << '.' << std::flush;

	bool x = fut.get();

	std::cout << "\n" << number << (x?" is":" is not") << " prime.\n";

	return 0;
}

