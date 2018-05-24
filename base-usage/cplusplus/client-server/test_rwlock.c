/*************************************************************************
	> File Name: test_rwlock.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 09 May 2017 10:35:41 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <pthread.h>

struct job{
	struct job *j_next;
	struct job *j_prev;
	pthread_t j_id; /* tells which thread handles this job */
	/* ... more stuff here need added */
};

struct queue{
	struct job	*q_head;
	struct job	*q_tail;
	pthread_rwlock_t	q_lock;
};

/*
 * Initialize a queue.
 */
int
queue_init(struct queue *qp)
{
	int err;
	qp->q_head = NULL;
	qp->q_tail = NULL;
	err = pthread_rwlock_init(&qp->q_lock, NULL);
	if(err != 0)
		return (err);
	/* ... continue initialization... */
	return (0);
}

/*
 * Destroy a queue.
 */
int queue_destroy(struct queue *qp)
{
	int err;
	err = pthread_rwlock_destroy(&qp->q_lock);
	return err;
}

/*
 * Insert a job at the head of the queue.
 */
void
job_insert(struct queue *qp, struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	jp->j_next = qp->q_head;
	jp->j_prev = NULL;
	if(qp->q_head != NULL)
		qp->q_head->j_prev = jp;
	else
		qp->q_tail = jp; /* list was empty */
	qp->q_head = jp;
	pthread_rwlock_unlock(&qp->q_lock);
}

/*
 * Append a job one the tail of the queue.
 */
void
job_append(struct queue *qp, struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	jp->j_next = NULL;
	jp->j_prev = qp->q_tail;
	if(qp->q_tail != NULL)
		qp->q_tail->j_next = jp;
	else
		qp->q_head = jp; /* list was empty */
	qp->q_tail = jp;
	pthread_rwlock_unlock(&qp->q_lock);
}

/*
 * Remove the given job from a queue.
 */
void
job_remove(struct queue *qp, struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	if(jp == qp->q_head){
		qp->q_head = jp->j_next;
		if(jp == qp->q_tail)
			qp->q_tail = NULL;
		else
			jp->j_next->j_prev = jp->j_prev; // jp->j_prev is NULL?
	} else if(jp == qp->q_tail){
		qp->q_tail = jp->j_prev;
		jp->j_prev->j_next = jp->j_next; // jp->j_next is NULL?
	} else {
		jp->j_prev->j_next = jp->j_next;
		jp->j_next->j_prev = jp->j_prev;
	}
	pthread_rwlock_unlock(&qp->q_lock);
}

/*
 * Find a job for the given thread ID.
 */
struct job *
job_find(struct queue *qp, pthread_t id)
{
	struct job *jp;
	if(pthread_rwlock_rdlock(&qp->q_lock) != 0)
		return (NULL);

	for(jp = qp->q_head; jp != NULL; jp = jp->j_next){
		if(pthread_equal(jp->j_id, id))
			break;
	}

	pthread_rwlock_unlock(&qp->q_lock);
	return (jp);
}



