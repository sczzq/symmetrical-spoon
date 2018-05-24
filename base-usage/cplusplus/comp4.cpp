#include <vector>
#include <future>
#include <thread>
#include <random>
#include <chrono>
#include <numeric>

using namespace std;

double comp4(vector<double>& v)
{
	if(v.size()<10000) return accumulate(v.begin(), v.end(), 0.0);

	auto v0 = &v[0];
	auto sz = v.size();

	auto f0 = async(accumulate, v0, v0+sz/4, 0.0);
	auto f1 = async(accumulate, v0+sz/4, v0+sz/2, 0.0);
	auto f2 = async(accumulate, v0+sz/2, v0+sz*3/4, 0.0);
	auto f3 = async(accumulate, v0*3/4, v0+sz, 0.0);

	return f0 + f1 + f2 + f3;
}

int main()
{
	audo die = bind(uniform_double_distribute<>{1,600}, dufault_random_engine{});
	
	vector<double> v;
	for(int i = 0; i < 1000*1000; i++){
		v.push_back(die());
	}

	auto t0 = chrono::high_resolution_clock::now();
	comp4(v);
	auto t1 = chrono::high_resolution_clock::now();
	std::cout << chrono::duration_cast<chrono::milliseconds>(t1-t0).count() << "msec\n";
}

