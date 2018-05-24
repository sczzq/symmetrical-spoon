/*************************************************************************
	> File Name: pthread_mutex_cond.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月20日 星期日 10时44分23秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE	17

static char *buffer;
static int start = 0; // start position of the content in cycle-buffer.
static int end = 0; // end position of the content in cycle-buffer.
static int buf_size = 0; // the size of the content in cycle-buffer.

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond_write = PTHREAD_COND_INITIALIZER;
pthread_cond_t  cond_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t  cond_exit = PTHREAD_COND_INITIALIZER;

typedef struct tid_info{
	pthread_t tid;
	int tid_num;
	char *role;
}tid_info;

int tid_num = 0;
tid_info tids[20];

#ifndef OK
#define OK 0
#endif

#ifndef FAIL
#define FAIL 1
#endif

/*
 * memory mode in cycle-buffer:
	
 * first: tail position is after head position
 * 0 1 2 3 4 5 6 7 8 9 A B C D E F 
 * - A B C D E F G H I - - - - - -
 *   |               |
 * start            end
 *
	
 * second: head position is after tail position
 * 0 1 2 3 4 5 6 7 8 9 A B C D E F 
 * H I - - - - - - - A B C D E F G
 *   |               |    
 *  end            start
 *
 * how to promise read and write can continure to execute.
 * 1, the buffer_size must double-times of the largest data
 *    which would to read or write.
 *    if not, starve with write with no-space and cannot
 *    read, and starve with read with no-enough-content
 *    and cannot write at the same time.
 *
 */

int pthread_msleep(int msecond)
{
	pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t  cnd = PTHREAD_COND_INITIALIZER;
	struct timespec ts;

	pthread_mutex_lock(&mtx);
	clock_gettime(CLOCK_REALTIME, &ts);
//	ts.tv_sec += 5;
	ts.tv_nsec += 1000000 * msecond;
	if(ts.tv_nsec > 1000000000){
		int sec = ts.tv_nsec / 1000000000;
		ts.tv_sec += sec;
		ts.tv_nsec -= (sec*1000000000);
	}
	int rc = 0;
	while (rc == 0)
		rc = pthread_cond_timedwait(&cnd, &mtx, &ts);
	pthread_mutex_unlock(&mtx);
}

int print_buffer(const char *role)
{
	int i = start;
	int ii = buf_size;
//	printf("pid: %u, %s: ", pthread_self(), role);
	printf("%s: ", role);
	while(ii--){
		i = i < BUFFER_SIZE ? i : (i % BUFFER_SIZE);
		printf("%c ", buffer[i++]);
	}
	printf("\n");
	return 0;
}

int show_info(const char *role)
{
//	printf("pid: %u, %s, start: %d, end: %d, buf_size: %d\n",
	printf("%s, start: %d, end: %d, buf_size: %d\n",
			role, start, end, buf_size);
	return 0;
}

int init()
{
	buffer = malloc(BUFFER_SIZE);
	if(!buffer){
		fprintf(stderr, "malloc in init error\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int check_write(int size)
{
	if(BUFFER_SIZE - buf_size > size){
		return OK;
	}
	return FAIL;
}

// check if has size bytes to read from.
int check_read(int size)
{
	if(buf_size >= size)
		return OK;
	return FAIL;
}

// unlock write, uncheck space, uncheck pre-condition.
int write_to_buffer(const char *data, size_t length)
{
	int i = 0;
	while(i < length){
		*(buffer+end) = *(data+i);
		end++;
		if(end >= BUFFER_SIZE){
			end %= BUFFER_SIZE;
		}
		i++;
	}
	buf_size += length;
	return 0;
}

// unlock read, uncheck content, uncheck pre-condition.
int read_from_buffer(char *dst, char length)
{
	int i = 0;
	while(i < length){
		// on this notebook, 
		// if using dst[i] to access the char * variable,
		// maybe unavailable, or get unexpect result.
		// reason here has no knowledge, need more spec.
		// 2018.5.20
		*(dst+i) = *(buffer+start);
		start++;
		if(start >= BUFFER_SIZE){
			start %= BUFFER_SIZE;
		}
		i++;
	}
	buf_size -= length;
	return 0;
}

int m_write(const char *data, size_t length)
{
	assert(data);
	//assert(length > -1); // type size_t, donot use this assert.
	if(length > BUFFER_SIZE){
		printf("write length is too large\n");
		return FAIL;
	}
	if(length == 0){
		printf("write length is zero\n");
		return OK;
	}

	pthread_mutex_lock(&mutex);
//	show_info("before write");

	while(check_write(length) != OK){
		int rc = pthread_cond_wait(&cond_write, &mutex);
//		printf("write wait result %d\n", rc);
	}

	write_to_buffer(data, length);

	print_buffer("after write");

	show_info("after write");

	pthread_cond_broadcast(&cond_read);

	pthread_mutex_unlock(&mutex);

	return OK;
}

int m_read(char *dst, size_t length)
{
	assert(dst);
	if(length == 0){
		printf("read length is zero\n");
		dst[0] = 0;
		return OK;
	}
	if(length > BUFFER_SIZE){
		printf("read length too large\n");
		return FAIL;
	}

	pthread_mutex_lock(&mutex);
//	show_info("before read");

	while(check_read(length) != OK){
		int rc = pthread_cond_wait(&cond_read, &mutex);
//		printf("read wait result %d\n", rc);
	}

	read_from_buffer(dst, length);

	print_buffer("after read");

	show_info("after read");

	pthread_cond_broadcast(&cond_write);

	pthread_mutex_unlock(&mutex);

	return OK;
}

void clear_tid()
{
	int i = 0;
	for(i = 0; i < tid_num; i++){
		if(pthread_equal(tids[i].tid, pthread_self())){
			printf("%s %d %lu exit\n", tids[i].role, tids[i].tid_num, tids[i].tid);
			free(tids[i].role);
			tid_num--;
			break;
		}
	}
}

void *consumer(void *UNUSED)
{
	char *dst = malloc(17);
	if(dst == NULL){
		printf("dst malloc error\n");
		return NULL;
	}
	int read_length = 15;

	srand(time(NULL));

	while(read_length > 0){
		int len = rand() % (BUFFER_SIZE/2);
		len = read_length % (BUFFER_SIZE/2);
		len++;
		if(OK == m_read(dst, len)){
//			printf("read OK\n");
		} else {
//			printf("read error\n");
		}
		read_length--;
//		pthread_msleep(150);
	}

	free(dst);
	clear_tid();
}

void *productor(void *UNUSED)
{
	// donot use stack variable to set parameter of
	// thread's start-routine.
//	char data[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 
//		       'A', 'B', 'C', 'D', 'E', 'F', '0'};

	char *s = "123456789ABCDEF0";
	char *data = malloc(strlen(s) + 1);
	sprintf(data, "%s", s);
	int write_length = 15;

	srand(time(NULL));
	while(write_length > 0){
		int len = rand() % (BUFFER_SIZE / 2);
		len = write_length % (BUFFER_SIZE / 2);
		len++;
		if (OK == m_write(data, len)){
//			printf("write OK\n");
		} else {
//			printf("write error\n");
		}
		write_length--;
//		pthread_msleep(100);
	}
	clear_tid();
} 
int test(int consumer_num, int productor_num)
{
	assert(consumer_num > 0);
	assert(productor_num > 0);
	pthread_t pid;
	while(consumer_num--){
		int res = pthread_create(&pid, NULL, consumer, NULL);
		if(res == 0){
			printf("create consumer #%lu, pid %d\n", consumer_num, pid);
		} else {
			printf("create thread error\n");
			exit(EXIT_FAILURE);
		}
		tids[tid_num].tid = pid;
		tids[tid_num].tid_num = tid_num;
		tids[tid_num].role = (char *)strdup("consumer");
		tid_num++;
		pthread_detach(pid);
	}

	pthread_msleep(100);

	while(productor_num--){
		int res = pthread_create(&pid, NULL, productor, NULL);
		if(res == 0){
			printf("create productor #%lu, pid %d\n", productor_num, pid);
		} else {
			printf("create thread error\n");
			exit(EXIT_FAILURE);
		}
		tids[tid_num].tid = pid;
		tids[tid_num].tid_num = tid_num;
		tids[tid_num].role = (char *)strdup("productor");
		tid_num++;
		pthread_detach(pid);
	}
	return 0;
}

int main()
{
	init();
	test(1, 1);
//	test(1, 2);
//	test(2, 1);
//	test(2, 2);

	while(tid_num > 0){
		pthread_msleep(1);
//		pthread_join(pids[pid_num], NULL);
	}
}

