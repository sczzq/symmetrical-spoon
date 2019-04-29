#include <iostream>
#include <stdio.h>

#include <thread>
#include <random>
#include <atomic>
#include <chrono>
#include <map>
#include <unordered_map>
#include <vector>
#include <mutex>

using namespace std;

// used in single thread
// non-lock container.
//
class TimePointQueueSingle {
	using TimePoint = chrono::system_clock::time_point;
	vector<TimePoint> tps;
public:
	int insert()
	{
		tps.push_back(chrono::system_clock::now());
	}
	size_t size()
	{
		return tps.size();
	}
};

class TimePointQueueNoLock {
	using TimePoint = chrono::system_clock::time_point;
	vector<TimePoint> tps;

//	unordered_map<thread::id, vector<TimePoint>> map_tps;

	vector<pair<thread::id, vector<TimePoint>>> map_tps;

	int thread_num;

public:
	TimePointQueueNoLock(int num) 
		: thread_num{num},
		map_tps(num)
	{
		for(auto & x : map_tps)
		{
			x.first = thread::id(0);
		}
	};
	int insert()
	{
		thread::id cid = this_thread::get_id();
		// TODO, here can use read-write lock
		//
		// but, there is an issue,
		// after changing subelement, the vector keeps consistence?
		// or, the point in array of vector are unchanged?
		//
		// read-lock
		// most time is in here
		for(auto & x : map_tps)
		{
			if(cid == x.first)
			{
				x.second.push_back(chrono::system_clock::now());
				return 0;
			}
		}
		// write-lock
		// init time is in here
		for (auto & x : map_tps)
		{
			if (x.first == thread::id(0))
			{
				x.second.push_back(chrono::system_clock::now());
				return 0;
			}
		}
	};

	// each thread has one vector
	// the elements in each vector are sorted, or sequence by time point
	// to get the point number of each second of all of the thread
	// 
	// example
	//	thread 1 has: 0.1 0.3 0.6 1.1
	//	thread 2 has: 0.1 0.3 0.7 1.3
	//	thread 3 has: 0.2 0.4 0.6 1.2
	// then
	//	from 0.1 to 1.1, there are 10 point
	//	from 0.2 to 1.2, there are 9 point
	//	from 0.3 to 1.3, there are 7 point
	//	and no other whole second.
	//
	int analysis()
	{
		long long total = 0;
		for (auto & x : map_tps)
		{
			cout << "thread: " << x.first
				<< ", number: " << x.second.size() << endl;
			total += x.second.size();
		}
		cout << "total: " << total << endl;
	};
};

class TimePointQueueLock {
	using TimePoint = chrono::system_clock::time_point;
	vector<TimePoint> tps;
	mutex mtx;

public:
	int insert()
	{
		lock_guard<mutex> guard(mtx);
		tps.push_back(chrono::system_clock::now());
	};

	int analysis()
	{
		int start = 0, end = 1;
		vector<int> ps;

		while(end < tps.size())
		{
			auto d = tps[end] - tps[start];
			if (d > 1s)
			{
				while (d > 1s)
				{
					start++;
					d = tps[end] - tps[start];
				}
				ps.push_back(end - start + 1);
			}
			end++;
		}
		int mint = 0xFFFFFF, maxt = 0;
		for(auto x : ps)
		{
			if (x < mint)
				mint = x;
			if (x > maxt)
				maxt = x;
		}
		cout << "total: " << tps.size() << ", min: " << mint << ",max: " << maxt << endl;
		auto start_time = tps[0];
		auto stop_time = tps[tps.size() - 1];
		auto dura = stop_time - start_time;
		cout << "elapsed time: "
			<<  dura.count()
			<< endl;
	};
};

template <typename Func>
class ThreadPool {
private:
	int capability;
	int size = 0;

	map<int, thread> thread_pool_priority;
	vector<thread> pool;

public:
	ThreadPool(int n) : capability{n}, pool(n)
	{};

	~ThreadPool() {
		for(auto &x : pool)
			x.join();
	};

	int submit_to(Func &func, int index);
};

template <typename Func>
int ThreadPool<Func>::submit_to(Func &func, int index)
{
	thread t{func, index};

	pool[size].swap(t);

	size++;
}

template <typename TimePointQueue>
auto get_func(atomic<int> &done, TimePointQueue &tpq)
{
	return [&](int index){
		using namespace std::chrono_literals;
		while(!done)
		{
			cout << "this is thread " << index << endl << flush;
			tpq.insert();
//			auto d1 = 1s;
//			this_thread::sleep_for(d1);
		}
		cout << "thread " << index << " exited\n" << flush;
	};
}

template <typename TimePointQueue>
auto get_func2(atomic<int> &done, TimePointQueue &tpq)
{
	return [&](int index){
		while(!done)
		{
			cout << "this is thread " << index;
			tpq.insert();
		}
//		cout << "thread " << index << " exited\n" << flush;
	};
}

template <typename TimePointQueue>
auto get_func3(atomic<int> &done, TimePointQueue &tpq)
{
	return [&](int index){
		while(!done)
		{
			tpq.insert();
		}
//		cout << "thread " << index << " exited\n" << flush;
	};
}

template <typename TimePointQueue>
int _test(int thread_num, TimePointQueue tpq)
{
	atomic<int> count{0}, done{0};

	auto func = get_func3(done, tpq);
	{
		ThreadPool<decltype(func)> pool(thread_num);
		for (int i = 0; i < thread_num; i++)
		{
			auto func = get_func3(done, tpq);
			pool.submit_to(func, i);
			count++;
		}
		this_thread::sleep_for(4s);
		done = 1;
	}
	tpq.analysis();
	cout << "all thread exited successed.\n";
}

template <typename TimePointQueue>
int _test2(int thread_num, TimePointQueue &tpq)
{
	atomic<int> count{0}, done{0};

	auto func = get_func3(done, tpq[0]);
	{
		ThreadPool<decltype(func)> pool(thread_num);
		for (int i = 0; i < thread_num; i++)
		{
			auto func = get_func3(done, tpq[i]);
			pool.submit_to(func, i);
			count++;
		}
		this_thread::sleep_for(4s);
		done = 1;
	}
//	tpq.analysis();
	cout << "all thread exited successed.\n";
}

int test(int thread_num)
{
	vector<TimePointQueueSingle> vstpq(thread_num);

	_test2(thread_num ,vstpq);

	long long total = 0;
	for(auto & x : vstpq)
	{
		cout << x.size() << " ";
		total += x.size();
	}
	cout << "\ntotal: " << total << endl;
}

int test1()
{
	test(10);
}

int test2()
{
	int thread_num = 1;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 2;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 3;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 4;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 8;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 12;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 16;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 20;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 24;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 28;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 32;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 48;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

	thread_num = 64;
	cout << "thread number: " << thread_num << endl;
	test(thread_num);
	this_thread::sleep_for(1s);

}

int main()
{
	cout << "hardware max thread: " << thread::hardware_concurrency() << endl;

	test2();

	cout << "OK\n";
}



// test2
// 使用带mutex的TimePointQueue
// 所有线程都往同一个队列中写数据
// 注意，下面的数据含义：
// total表示队列中全部数据的数目
// min表示每秒的最小值
// max表示每秒的最大值
// 计算方式见TimePointQueueLock中的analysis
//
// 测试数据
// hardware max thread: 12
// thread number: 1
// total: 61878067, min: 11695653,max: 19152354
// elapsed time: 4000004851
// all thread exited successed.
// thread number: 2
// total: 21777743, min: 4911312,max: 6189992
// elapsed time: 4000072421
// all thread exited successed.
// thread number: 3
// total: 24150172, min: 5336582,max: 6760085
// elapsed time: 4000087678
// all thread exited successed.
// thread number: 4
// total: 21126077, min: 4022294,max: 6192794
// elapsed time: 4000093529
// all thread exited successed.
// thread number: 8
// total: 15551796, min: 3672538,max: 4137380
// elapsed time: 4000544109
// all thread exited successed.
// thread number: 12
// total: 12664164, min: 2989390,max: 3347474
// elapsed time: 4000714911
// all thread exited successed.
// thread number: 16
// total: 12977394, min: 3063587,max: 3431505
// elapsed time: 4000929201
// all thread exited successed.
// thread number: 20
// total: 13253757, min: 3126018,max: 3502964
// elapsed time: 4001889523
// all thread exited successed.
// thread number: 24
// total: 13537642, min: 3200744,max: 3584376
// elapsed time: 4001542588
// all thread exited successed.
// thread number: 28
// total: 13488789, min: 3194869,max: 3578702
// elapsed time: 4002255850
// all thread exited successed.
// thread number: 32
// total: 13515909, min: 3190008,max: 3571235
// elapsed time: 4002333102
// all thread exited successed.

// test2
// 每个线程一个队列，TimePointQueueSingle
// 每个线程单独向一个队列写数据
// 线程间不共享队列
// 
// 数据说明
// total表示所有线程共同的数据的数目
// total上一行表示每个线程的数据的数目
//
// 测试数据
// hardware max thread: 12
// thread number: 1
// all thread exited successed.
// 80341963 
// total: 80341963
// thread number: 2
// all thread exited successed.
// 77490309 77532869 
// total: 155023178
// thread number: 3
// all thread exited successed.
// 65929796 52205168 50903434 
// total: 169038398
// thread number: 4
// all thread exited successed.
// 55697775 49212982 41410698 62739952 
// total: 209061407
// thread number: 8
// all thread exited successed.
// 33554433 46316204 39917039 33554433 28548102 50235860 37470017 56476202 
// total: 326072290
// thread number: 12
// all thread exited successed.
// 41692967 42834098 29887429 33554433 25383874 33978136 33554433 29407993 32797548 33554433 33554433 34263397 
// total: 404463174
// thread number: 16
// all thread exited successed.
// 33554433 26718393 23851951 24361458 26742364 21366031 21643307 27681230 24783163 22043434 26448466 29298154 32273304 20690643 19842219 28021149 
// total: 409319699
// thread number: 20
// all thread exited successed.
// 33554433 17764888 27601014 20438512 18167192 20183912 17195304 25177447 19383037 22540772 19185904 22233476 16828223 21917297 16777217 19605846 25653700 19309368 17835362 23094334 
// total: 424447238
// thread number: 24
// all thread exited successed.
// 23619337 16906207 18327252 17171894 18886297 16896703 16777217 18817898 17290265 16777217 26129872 16777217 16777217 16777217 21764400 16777217 16777217 18170533 19736948 16777217 16777217 18562954 19737223 27673614 
// total: 450686350
// thread number: 28
// all thread exited successed.
// 21483405 16777217 16777217 16777217 16937507 16777217 16777217 18704671 16777217 16777217 16777217 16777217 16777217 16777217 16777217 17503877 16777217 20168191 16777217 16568520 16777217 16777217 15526911 16777217 16777217 16777217 16777217 16777217 
// total: 479214639
// thread number: 32
// all thread exited successed.
// 18805990 16187964 16777217 16777217 16777217 16777217 14869057 16777217 16777217 16777217 16777217 16777217 16777217 16777217 15270157 14167889 16396423 16777217 15569846 14478335 15583014 14455358 14123493 16777217 16777217 14261847 16777217 16777217 17766709 15520464 15290587 16777217 
// total: 517959822
// thread number: 48
// all thread exited successed.
// 13510143 15042977 9344511 14422527 10902196 11897343 9379981 11553791 9753599 10615807 10842112 11581439 9357823 9117695 8388609 9388031 9300062 11749991 9447935 8962559 10018815 8688768 8936959 11288575 8388609 8649470 8389631 8796493 8628774 11031356 8388609 10539519 11377151 8388609 10199396 9571618 8999260 8388609 10418175 8971775 8388609 14440915 11471359 10729770 14416693 9935350 10768461 15193740 
// total: 497964199
// thread number: 64
// all thread exited successed.
// 8388609 8020479 8388609 8388609 8388609 8019319 7964671 8388609 8388609 8388609 8388609 8388609 8388609 7708671 7538687 7834111 8388609 8003583 7382015 7924735 8388609 8388609 8388609 8388609 8221695 7869951 8388609 8388609 8388609 7517856 8388609 8388609 8388609 7978075 8388609 8388609 8135679 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8388609 8036863 8388609 8846539 8388609 8388609 8388609 8388609 8388609 7746047 8388609 
// total: 529013599



