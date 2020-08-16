#include <iostream>
#include <deque>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;


deque<int> queue; 
int max_size = 10;
int cur = 1;
static int max_cur = 300;

static condition_variable pcv, ccv;
static mutex m;

bool pready = false, cready = false;

static int
consumer()
{
	cout << "start consumer\n";
	while(1)
	{
		unique_lock<mutex> lk(m);

		while(queue.size() == 0)
		{
			pcv.wait(lk, []{return pready;});
		}
		pready = false;

		auto it = queue.begin();
		cout << "consumer:               " << *it << "\n";

		queue.pop_front();
		cready = true;


		lk.unlock();

		ccv.notify_one();

		this_thread::sleep_for(std::chrono::milliseconds(500));

		lk.lock();
		if(cur > max_cur)
		{
			lk.unlock();
			break;
		}
		lk.unlock();
	}
}

static int
producer()
{
	this_thread::sleep_for(std::chrono::milliseconds(500));
	cout << "start producer\n";
	while(1)
	{
		unique_lock<mutex> lk(m);

		while(queue.size() >= max_size)
		{
			ccv.wait(lk, []{return cready;});
		}

		cready = false;

		queue.push_back(++cur);
		cout << "producer: " << cur << "\n";

		pready = true;

		lk.unlock();

		pcv.notify_one();

		this_thread::sleep_for(chrono::milliseconds(500));

		lk.lock();
		if(cur > max_cur)
		{
			lk.unlock();
			break;
		}
		lk.unlock();
	}
}

int main()
{
	thread t10(producer);
	thread t11(producer);
	thread t12(producer);

	thread t20(consumer);
	thread t21(consumer);
	thread t22(consumer);

	t10.join();
	t11.join();
	t12.join();

	t20.join();
	t21.join();
	t22.join();
}



