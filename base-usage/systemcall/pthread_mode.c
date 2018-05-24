/*************************************************************************
	> File Name: pthread_mode.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月20日 星期日 21时57分50秒
 ************************************************************************/

/*
 * pthread model, used by testing
 */

struct tid_info{
	pthread_t tid;
	int tid_num;
	char *role;
}tid_info;

int tids = 0;
tid_info tids[20];

