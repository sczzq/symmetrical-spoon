/*************************************************************************
	> File Name: pex64.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 03:25:00 PM CST
 ************************************************************************/

#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Random_int{
public:
	Random_int(int low, int high):dist{low, high}{};
	int operator()(){return dist(re);};
private:
	default_random_engine re;
	uniform_int_distribution<> dist;

};

int main()
{
	Random_int rnd {0, 29};
	vector<int> histogram(30);
	for(int i=0; i<2000; i++)
		++histogram[rnd()];

	for(int i=0; i < histogram.size(); i++){
		cout << i << ": ";
		int j = histogram[i];
		for(; j>0; j--) cout << "*";
		cout << endl;
	}
}

