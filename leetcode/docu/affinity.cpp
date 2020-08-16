#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

int main()
{
	unsigned num_cpus = std::thread::hardware_concurrency();
	cout << "Launching " << num_cpus << " threads\n";

	mutex iomutex;

	vector<thread> threads(num_cpus);
	for(unsigned i = 0; i < num_cpus; i++)
	{
		threads[i] = thread([&iomutex, i] {
				while(1)
				{
					{
						lock_guard<mutex> iolock(iomutex);
						cout << "thread #" << i << " is running on CPU " 
							<< sched_getcpu() << "\n" ;
					}
					this_thread::sleep_for(chrono::milliseconds(1000));
				}
			}
			);
	}

	for(auto & t : threads){
		t.join();
	}

	return 0;
}

