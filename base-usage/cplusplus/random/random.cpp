/*************************************************************************
	> File Name: random.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 06 Apr 2018 02:01:03 PM CST
 ************************************************************************/

#include <iostream>
#include <random>
#include <fstream>
#include <cassert>
#include <chrono>

int main(int argc, char *argv[])
{
	assert(argc > 2);

	std::ofstream out {std::string(argv[1])};
	int number = std::atoi(argv[2]);

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
//	std::uniform_int_distribution<int> distribution(0, 100);
//	std::binomial_distribution<int> distribution(100,0.5);
//	std::geometric_distribution<int> distribution(0.5);
//	std::poisson_distribution<int> distribution(50);
	std::exponential_distribution<double> distribution(3.5);
	while(number-- > 0){
		out << number << " ";
		out << distribution(generator);
		out << "\n";
	}
	out.close();
	return 0;
}
