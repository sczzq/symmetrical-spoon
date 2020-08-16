#include <iostream>
#include <deque>
#include <vector>



#include <pthread.h>
#include <unistd.h>

using namespace std;


#define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
	do {perror(msg), exit(EXIT_FAILURE); } while(0)


deque<int> queue; 
int max_size = 10;
int cur = 1;

static pthread_cond_t pcond = PTHREAD_COND_INITIALIZER,
			   ccond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void *
consumer(void *arg)
{
	sleep(2);
	cout << "start consumer\n";
	float consume_time = *(int *)arg + 1;
	consume_time /= 2;
	while(1)
	{
		pthread_mutex_lock(&mutex);

		while(queue.size() == 0)
		{
			pthread_cond_wait(&pcond, &mutex);
		}

		auto it = queue.begin();
		cout << "consumer:               " << *it << "\n";

		queue.pop_front();

		pthread_mutex_unlock(&mutex);

		pthread_cond_signal(&ccond);

		sleep(consume_time);
	}
}

static void *
producer(void *arg)
{
	sleep(2);
	cout << "start producer\n";
	int s = *(int *)arg;
	float produce_time = s + 1;
	produce_time /= 2;
	while(1)
	{
		pthread_mutex_lock(&mutex);

		while(queue.size() >= max_size)
		{
			pthread_cond_wait(&ccond, &mutex);
		}

		queue.push_back(++cur);
		cout << "producer: " << cur << "\n";

		pthread_mutex_unlock(&mutex);

		pthread_cond_signal(&pcond);

		sleep(produce_time);
	}
}

int main()
{
	int s;

	cout << sizeof(pthread_t) << "\n";
	cout << sizeof(pid_t) << "\n";

	vector<pthread_t> pro_pids, con_pids;
	int producer_count = 3, consumer_count = 3;

	for(int i = 1; i < producer_count; i++)
	{
		pthread_t pid;
		s = pthread_create(&pid, NULL, &producer, &i);
		if(s != 0)
		{
			handle_error_en(s, "pthread_create consumer");
		}
		cout << pid << "\n";
		pro_pids.push_back(pid);
	}

	for(int i = 1; i < consumer_count; i++)
	{
		pthread_t pid;
		s = pthread_create(&pid, NULL, &consumer, &i);
		if(s != 0)
		{
			handle_error_en(s, "pthread_create producer");
		}
		cout << pid << "\n";
		con_pids.push_back(pid);
	}


	vector<pthread_t> pids;

	pids.insert(pids.end(), con_pids.begin(), con_pids.end());
	pids.insert(pids.end(), pro_pids.begin(), pro_pids.end());

	for(pthread_t pid : pids)
	{
		cout << pid << "\n";
		s = pthread_join(pid, NULL);
		if(s != 0)
		{
			handle_error_en(s, "pthread_join");
		}
	}



	pthread_cond_destroy(&pcond);
	pthread_cond_destroy(&ccond);
	pthread_mutex_destroy(&mutex);
}


