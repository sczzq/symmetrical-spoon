/*************************************************************************
	> File Name: testRandom.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 30 May 2017 02:16:58 AM CST
 ************************************************************************/

#include <iostream>
#include <random>
#include <vector>
#include <unordered_set>

using namespace std;

// to see zzq.mark
// generate 10 million number in [0, 1000*1000*10).
//
class Random_int{
public:
	Random_int(int low, int high):dist{low, high}{};
	int operator()(){return dist(re);};
private:
	default_random_engine re;
	uniform_int_distribution<> dist;

};

int foo(int s){
	int size = s;
	Random_int rnd {0, size};
	vector<int> vr;

	vr.reserve(size+1);
	for(int i=0; i<size; i++)
		vr[i] = 0;

	int v;
	while(size >= 0){
		v = rnd();
		if(vr[v] == 0){
			vr[v] = 1;
			--size;
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	std::cout << argv[0] << std::endl;
	argc = atoi(argv[1]);
	foo(argc);
}



