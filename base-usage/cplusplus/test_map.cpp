/*************************************************************************
	> File Name: test_map.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 10 May 2018 09:50:10 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <chrono>

using std::map;
using namespace std::chrono;

int test2()
{
	int q1 = 1000000;
	int max_num = 10000000;

	map<int, int> map1;
	auto start = std::chrono::system_clock::now();
}

int test1()
{
	int q1 = 1000000;
	map<int, int> map1;
	auto start = std::chrono::system_clock::now();
	for(int i = 0; i < q1; i++){
		int k1=i, k2=i;
		map1.insert({k1, k2});
	}
	auto end = std::chrono::system_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << duration << " us\n";
}

int main()
{
	test1();
}
