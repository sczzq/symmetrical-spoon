#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MARK_START_TIME  \
	struct timeval tv_start, tv_stop; \
	gettimeofday(&tv_start, NULL);

#define MARK_STOP_TIME \
	gettimeofday(&tv_stop, NULL); \
	if (tv_stop.tv_usec < tv_start.tv_usec) \
	{ \
		tv_stop.tv_usec += 1000*1000; \
		tv_stop.tv_sec--; \
	} \
 \
	printf("Count[%d] Elapsed[%ld.%ld]\n", \
			times, \
			tv_stop.tv_sec - tv_start.tv_sec, \
			tv_stop.tv_usec - tv_start.tv_usec);

int test1(int times)
{
	MARK_START_TIME;

	int i = times;
	while(i--)
	{
		pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

		pthread_mutex_lock(&mutex);

		pthread_mutex_unlock(&mutex);
	}

	MARK_STOP_TIME;
}

struct test2_data{
	pthread_mutex_t *mutex;
	int times;
};

void *test2_loop(void *arg)
{
	MARK_START_TIME;

	struct test2_data *data = (struct test2_data *)arg;
	pthread_mutex_t *mutex = data->mutex;
	int times = data->times;

	int i = times;
	while(i--)
	{
		pthread_mutex_lock(mutex);

		pthread_mutex_unlock(mutex);
	}

	MARK_STOP_TIME;
}

int test2(int times)
{
	printf("start test2\n");

	struct test2_data data;
	data.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	data.times = times;

	pthread_mutex_init(data.mutex, NULL);

	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_t tid1, tid2;
	pthread_create(&tid1, &attr, test2_loop, &data);
	pthread_create(&tid2, &attr, test2_loop, &data);

	pthread_attr_destroy(&attr);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("stop test2\n");
	return 0;
}

struct test3_data {
	pthread_mutex_t *mutex;
	pthread_cond_t *cond1;
	pthread_cond_t *cond2;
	int times;
};

void *test3_loop1(void *arg)
{
	printf("start test3_loop1\n");
	MARK_START_TIME;

	struct test3_data *data = (struct test3_data *)arg;
	pthread_mutex_t *mutex = data->mutex;
	pthread_cond_t *cond1 = data->cond1;
	pthread_cond_t *cond2 = data->cond2;
	int times = data->times;

	int i = times;
	while(i--)
	{
		if (i < 3)
		{
			pthread_cond_signal(cond1);
			printf("loop1[%d]\n", i);
			break;
		}
		pthread_mutex_lock(mutex);
		pthread_cond_signal(cond1);
		pthread_cond_wait(cond2, mutex);
		pthread_mutex_unlock(mutex);
	}

	MARK_STOP_TIME;
	printf("stop test3_loop1\n");
}

void *test3_loop2(void *arg)
{
	printf("start test3_loop2\n");
	MARK_START_TIME;

	struct test3_data *data = (struct test3_data *)arg;
	pthread_mutex_t *mutex = data->mutex;
	pthread_cond_t *cond1 = data->cond1;
	pthread_cond_t *cond2 = data->cond2;
	int times = data->times;

	int i = times;
	while(i--)
	{
		if (i < 3)
		{
			pthread_cond_signal(cond2);
			printf("loop2[%d]\n", i);
			break;
		}
		pthread_mutex_lock(mutex);
		pthread_cond_signal(cond2);
		pthread_cond_wait(cond1, mutex);
		pthread_mutex_unlock(mutex);
	}

	MARK_STOP_TIME;
	printf("stop test3_loop2\n");
}

int test3(int times)
{
	printf("test3 starting\n");

	struct test3_data data;
	data.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	data.cond1 = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
	data.cond2 = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
	data.times = times;

	pthread_mutex_init(data.mutex, NULL);

	pthread_cond_init(data.cond1, NULL);
	pthread_cond_init(data.cond2, NULL);

	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_t tid1, tid2;
	pthread_create(&tid1, &attr, test3_loop1, &data);
	pthread_create(&tid2, &attr, test3_loop2, &data);

	pthread_attr_destroy(&attr);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("test3 stopped\n");
}

struct test4_data {
	pthread_mutex_t *mutex;
	int times;
};

void *test4_loop(void *arg)
{
	MARK_START_TIME;

	struct test4_data *data = arg;
	int times = data->times;

	int i = data->times;
	while(i--)
	{
		pthread_mutex_lock(data->mutex);
		pthread_mutex_unlock(data->mutex);
	}

	MARK_STOP_TIME;

	return NULL;
}

int test4(int times, int threads)
{
	printf("test4 starting\n");
	pthread_t *tids = (pthread_t *)malloc(sizeof(pthread_t*) * threads);

	struct test4_data data;
	data.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	data.times = times;

	pthread_mutex_init(data.mutex, NULL);

	pthread_attr_t attr;
	pthread_attr_init(&attr);

	int i = 0;
	for (i = 0; i < threads; i++) {
		pthread_create(tids + i, &attr, test4_loop, (void *) &data);
	}

	for (i = 0; i < threads; i++) {
		pthread_join(tids[i], NULL);
	}

	printf("test4 stopped\n");
}

int main()
{
	test1(1000*1000);
//	test1(1000*1000*100);

	test2(1000*1000);

	test3(1000*1000);

	test4(1000*1000, 1000);
}

