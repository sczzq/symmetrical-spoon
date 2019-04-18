#include <random>
#include <vector>
#include <iostream>

int random_vector(std::vector<int> &vi, int min, int max, int size)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dis(min, max);

	while(size--)
		vi.push_back(dis(gen));

	return 0;
}

