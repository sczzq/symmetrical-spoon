/*************************************************************************
  > File Name: threadpool.c
  > Author: ziqiang
  > Mail: ziqiang_free@163.com 
  > Created Time: 2018年05月23日 星期三 10时38分42秒
 ************************************************************************/

/*
 * gcc `pkg-config --cflags --libs glib-2.0 gthread-2.0` threadpool.c
 */

#include <stdio.h>
#include <glib.h>
#include <string.h>

/** 全局锁*/
GMutex g_lock;

#define MAX_THREAD_NUM 10

/**
 * @brief 线程池回调函数，线程执行的主体函数
 */
void show_result(gpointer str, gpointer data)
{
	g_mutex_lock(&g_lock);
	printf("The result is : %s\n", (char*)str);
	g_mutex_unlock(&g_lock);
	if(1)
	{
		g_printf("thread[%lu] is running...\n",pthread_self());
		sleep(1);
	}
}

int main()
{
	char *str = "thread_pool example";
	char *dstr = malloc(strlen(str) + 80);
	memset(dstr, 0, strlen(str) + 80);
	memcpy(dstr, str, strlen(str));
	int count = 0;
	int g_thread_num = 0;
	GThreadPool *thread_pool;

	/**
	 *
	 * 初始化互斥锁，NULL表示使用默认的快速互斥锁。
	 *
	 */
	g_mutex_init(&g_lock);

	thread_pool = g_thread_pool_new(show_result, NULL, MAX_THREAD_NUM, TRUE, NULL);

	if (thread_pool == NULL)
	{
		printf("g_thread_pool_new failed!\n");
		return -1;
	}
	/**
	 * 调用20次线程池
	 * 实际线程池中最多有10个线程同时运行
	 */
	for (count; count < 20; count++)
	{
		g_mutex_lock(&g_lock);
		sprintf(dstr+strlen(dstr), ".%d", count);
		printf("push %d\n", count);
		g_mutex_unlock(&g_lock);
		g_thread_pool_push(thread_pool, (gpointer)dstr, NULL);
	}

	g_thread_num =  g_thread_pool_get_max_threads(thread_pool);

	printf("Max number in the pthread pool: %d\n", g_thread_num);
	g_thread_pool_free(thread_pool, 0, 1);

	return;
}

