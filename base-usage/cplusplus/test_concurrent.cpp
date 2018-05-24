/*************************************************************************
	> File Name: test_concurrent.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月15日 星期二 14时05分40秒
 ************************************************************************/

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

/*
 * to see test_thread2.cpp
 *
 * compile error in f2(vector<int>& v)
 *
 * to see https://stackoverflow.com/questions/28950835/c-error-no-type-named-type-in-class-stdresult-ofvoid-stdunordered
 *
 * I could compile your code successfully with MSVC2013. However, thread() works passing copies of its argument to the new thread. This means that if your code would compile on your compiler, each thread wourd run with its own copy of ht, so that at the end, main's ht would be empty.
 *
 * GCC doesn't compile with this weird message. You can get rid of it by using the reference wraper with thread:
 *
 * t[0] = thread(thread_add, std::ref(ht), 0, 9);
 * t[1] = thread(thread_add, std::ref(ht), 10, 19);
 * This will compile succesfully. And each reference used by the threads would refer to the same object.
 *
 * However, there are high chances that you'll get some runtime error or unexpected results. This is because two threads are concurently trying to insert into ht. But unordered_map is not thread safe, so these racing conditions might cause ht to reach an unstable state (i.e. UB, i.e. potential segfault).
 *
 * To make it running properly, you have to protect your concurent accesses:
 *
 * '''
 *
 */

//void f2(vector<int>& v){
void f2(vector<int> v){
	cout << "in function f\n";
	for(auto x : v)
		cout << x << " ";
	cout << endl;
}

struct F2{
	vector<int> v;
	F2(vector<int>& vv) : v{vv} { }
	void operator()() {
		cout << "in class F\n";
	}
};

void test()
{
	vector<int> some_vec{1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> vec;
	vec.push_back(10);

	thread t1 {f2, vec};
	thread t2 {F2{vec}};

	t1.join();
	t2.join();
}

int main()
{
	test();
}


