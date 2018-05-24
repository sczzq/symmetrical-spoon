/*************************************************************************
	> File Name: test_thread2.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 28 Apr 2017 12:04:27 PM CST
 ************************************************************************/

#include <iostream>
#include <thread> // thread sleep_for
#include <chrono> // high_resolution_clock millseconds   duration_cast nanoseconds high_resolution_clock::time_point
#include <random> // default_random_engine uniform_int_distribution
#include <mutex> // mutex 
#include <condition_variable> // condition_variable 
#include <queue> // queue
using namespace std;

void f(int dura)
{
	auto t0 = chrono::high_resolution_clock::now();
	this_thread::sleep_for(chrono::milliseconds{dura});
	auto t1 = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::nanoseconds> (t1-t0).count() << " nanoseconds passed" << '\n';
}

class Rand_int{
public:
	Rand_int(int low, int high): dist{low, high} { }
	int operator()(){ return dist(re); }
private:
	default_random_engine re;
	uniform_int_distribution<> dist;
};

class Message{
	chrono::high_resolution_clock::time_point t0, t1; // t1-t0 alive time between after produced and consumed.
	int dura; // producing time
	Rand_int rnd { 20, 200 };
	int mid;
public:
	Message(int m){
		mid = m;
//		t0 = chrono::high_resolution_clock::now();
//		dura = chrono::duration_cast<chrono::nanoseconds> (t0).count() % rnd();
		dura = rnd();
		this_thread::sleep_for(chrono::milliseconds{dura});
		cout << "message id: " << mid << ": using " << dura << " milliseconds to produce\n";
		t0 = chrono::high_resolution_clock::now();
	}
	void operator()(){
		this_thread::sleep_for(chrono::milliseconds{100});
	}
	~Message(){
		t1 = chrono::high_resolution_clock::now();
		cout << "message id: " << mid << ": " << chrono::duration_cast<chrono::nanoseconds> (t1-t0).count() << " nanoseconds alive before consumed and after produced\n";
	}
};

class AtomicMessage{
	queue<Message> megs;
	condition_variable mcond;
	mutex mu;
	int ids;
public:
	AtomicMessage():ids{0} { }

	void produce(){
		ids++;
		unique_lock<mutex> lck{mu};

		megs.push(Message{ids});

		mcond.notify_one();
	}

	void consume(){
		unique_lock<mutex> lck{mu};
		mcond.wait(lck);

		Message msg = megs.front();
		msg();
		megs.pop();

		lck.unlock();

	}
};

class class_producer{
	AtomicMessage* amegs;
public:
	class_producer(AtomicMessage* am) : amegs{am} { }

	bool operator()(){
		while(true){
			amegs->produce();
		}
	}
};

class class_consumer{
	AtomicMessage* amegs;
public:
	class_consumer(AtomicMessage* am) : amegs{am} { }

	bool operator()(){
		while(true){
			amegs->consume();
		}
	}
};

void func_producer(AtomicMessage* amegs)
{
	while(true){
		amegs->produce();
	}
}

void func_consumer(AtomicMessage* amegs)
{
	while(true){
		amegs->consume();
	}
}

void hh()
{
	AtomicMessage amegs;

	thread t1{func_producer, &amegs};
	thread t2{func_consumer, &amegs};

	t1.join();
	t2.join();
}

int main()
try
{
//	f();
	hh();
}
catch (std::exception & e)
{
	std::cout << e.what() << std::endl;
}

