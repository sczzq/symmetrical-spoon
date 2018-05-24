
#ifndef _MRANDOM_H__
#define _MRANDOM_H__

#include <iostream>
#include <chrono>
#include <random>

namespace Anomynous{

int RandomUint64_t(void)
{
	using gene = std::default_random_engine;
	using dist = std::uniform_int_distribution<uint64_t>;
	unsigned int seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::minstd_rand0 g1(seed1);
	return g1();
}

}
#endif
