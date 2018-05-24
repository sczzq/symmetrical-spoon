/*************************************************************************
	> File Name: pex63.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 02:25:25 PM CST
 ************************************************************************/

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

int main()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	system_clock::duration dtn = t1.time_since_epoch();
	while(1){
		t1 = high_resolution_clock::now();
		dtn = t1.time_since_epoch();
		cout << dtn.count() << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	return 0;
}
