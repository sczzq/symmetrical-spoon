
#include <thread>
#include <vector>
#include <map>
#include <mutex>

template <typename Func>
class ThreadPool {
	using std::map;
	using std::vector;
	using std::thread;
	using std::map;
	using std::mutex;
private:
	int capability;
	int size = 0;

	map<int, thread> thread_pool_priority;
	vector<thread> pool;

	mutex mtx;

public:
	ThreadPool(int n) : capability{n}, pool(n)
	{};

	~ThreadPool() {
		for(auto &x : pool)
			x.join();
	};

	int submit_to(Func &func, int index) noexcept
	{
		lock_guard<mutex> lg(mtx);
		if (size >= capability)
		{
			return -1;
		}

		thread t{func, index};
		pool[size].swap(t);
		size++;
	};
};


/*
template <typename Func>
int ThreadPool<Func>::submit_to(Func &func, int index)
{
	thread t{func, index};

	pool[size].swap(t);

	size++;
}
*/


