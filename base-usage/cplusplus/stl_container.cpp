#include <iostream>
#include <random>
#include <functional>
#include <chrono>
#include <cassert>
#include <limits>

#include <vector>
#include <map>

using namespace std;
using namespace std::chrono;

void my_random()
{
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(numeric_limits<float>::min(), numeric_limits<float>::max());
	auto gen = bind(distribution, generator);
}

template<typename T>
class use_vector
{
public:
	use_vector(int times)
	:t{times},
	tp {steady_clock::now()}
	{
		assert(t<100*1000*1000); // title to 8 seconds in this machine. and 80 seconds is too long to ....
		vector<float> v{}; 
		float tt = (float)t;

		for(float f=0; f<t; f+=1.0)
			v.push_back(f);

		steady_clock::duration d = steady_clock::now() - tp;
		cout << "vector " << t << " took " << duration_cast<milliseconds>(d).count() << "ms" << endl;

		if(t < 100){
			for(auto& mm : v)
				cout << mm << endl;
		}
	}

	~use_vector(){
	}
private:
	int t; // total element number.
	steady_clock::time_point tp;
};

template<typename TK, typename TV>
class use_map
{
public:
	use_map(int times)
	:t{times},
	tp {steady_clock::now()}
	{
		assert(t<100*1000*1000); // title to 8 seconds in this machine. and 80 seconds is too long to ....
		map<TK, TV> v{}; 
		float tt = (float)t;

		for(float ff=0; ff<tt; ff+=1.0){
			v.insert({ff, ff});
		}

		steady_clock::duration d = steady_clock::now() - tp;
		cout << "map " << t << " took " << duration_cast<milliseconds>(d).count() << "ms" << endl;

		if(t < 100){
//			for(auto& mm : v)
//				cout << mm << ", " << mm << endl;
		}
	}

	~use_map(){
	}
private:
	int t; // total element number.
	steady_clock::time_point tp;
};


int main()
{
	int times = 10;

	for(int i = 0; i < 7; i++){
		use_vector<int> vec{times};
		times *= 10;
	}

	times = 10;
	for(int i = 0; i < 7; i++){
		use_map<float, float> m{times};
		times *= 10;
	}

	return 0;
}

