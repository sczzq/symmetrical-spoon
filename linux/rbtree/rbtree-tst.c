/*
 * =============================================================================
 *
 *       Filename:  rbtree-tst.c
 *
 *    Description:  rbtree testcase.
 *
 *        Created:  09/02/2012 11:39:34 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#include "rbtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

struct mynode {
  	struct rb_node node;
  	char *string;
};

struct rb_root mytree = RB_ROOT;

struct mynode * my_search(struct rb_root *root, char *string)
{
  	struct rb_node *node = root->rb_node;

  	while (node) {
  		struct mynode *data = container_of(node, struct mynode, node);
		int result;

		result = strcmp(string, data->string);

		if (result < 0)
  			node = node->rb_left;
		else if (result > 0)
  			node = node->rb_right;
		else
  			return data;
	}
	return NULL;
}

int my_insert(struct rb_root *root, struct mynode *data)
{
  	struct rb_node **new = &(root->rb_node), *parent = NULL;

  	/* Figure out where to put new node */
  	while (*new) {
  		struct mynode *this = container_of(*new, struct mynode, node);
  		int result = strcmp(data->string, this->string);

		parent = *new;
  		if (result < 0)
  			new = &((*new)->rb_left);
  		else if (result > 0)
  			new = &((*new)->rb_right);
  		else
  			return 0;
  	}

  	/* Add new node and rebalance tree. */
  	rb_link_node(&data->node, parent, new);
  	rb_insert_color(&data->node, root);

	return 1;
}

void my_free(struct mynode *node)
{
	if (node != NULL) {
		if (node->string != NULL) {
			free(node->string);
			node->string = NULL;
		}
		free(node);
		node = NULL;
	}
}

#define NUM_NODES 32

int test1()
{
	struct mynode *mn[NUM_NODES];

	/* *insert */
	int i = 0;
	printf("insert node from 1 to NUM_NODES(32): \n");
	for (; i < NUM_NODES; i++) {
		mn[i] = (struct mynode *)malloc(sizeof(struct mynode));
		mn[i]->string = (char *)malloc(sizeof(char) * 4);
		sprintf(mn[i]->string, "%d", i);
		my_insert(&mytree, mn[i]);
	}
	
	/* *search */
	struct rb_node *node;
	printf("search all nodes: \n");
	for (node = rb_first(&mytree); node; node = rb_next(node))
		printf("key = %s\n", rb_entry(node, struct mynode, node)->string);

	/* *delete */
	printf("delete node 20: \n");
	struct mynode *data = my_search(&mytree, "20");
	if (data) {
		rb_erase(&data->node, &mytree);
		my_free(data);
	}

	/* *delete again*/
	printf("delete node 10: \n");
	data = my_search(&mytree, "10");
	if (data) {
		rb_erase(&data->node, &mytree);
		my_free(data);
	}

	/* *delete once again*/
	printf("delete node 15: \n");
	data = my_search(&mytree, "15");
	if (data) {
		rb_erase(&data->node, &mytree);
		my_free(data);
	}

	/* *search again*/
	printf("search again:\n");
	for (node = rb_first(&mytree); node; node = rb_next(node))
		printf("key = %s\n", rb_entry(node, struct mynode, node)->string);

	return 0;
}

int test2()
{
	struct mynode *mn;
	int q1 =  10000000;
	int q2 =  10000000; // the limitation of the maximum id in operation..
	int nums = 1000000; // number of operation.
	int *key_num1 = malloc(q1 * sizeof(int));
	if(!key_num1){
		fprintf(stderr, "malloc error %lu\n", q1*sizeof(int));
		exit(EXIT_FAILURE);
	}
	int *key_num2 = malloc(q2 * sizeof(int));
	if(!key_num2){
		fprintf(stderr, "malloc error %lu\n", q2*sizeof(int));
		exit(EXIT_FAILURE);
	}

	/* *insert */
	int i = 0;
	struct timeval tv1, tv2, tv3;
	gettimeofday(&tv1, NULL);
	srand(time(NULL) % tv1.tv_usec);
	for (i = 0; i < nums; i++) { // nums operation.
		int num = rand() % q1; // q1 is limitation of the id.
		key_num1[num] = 1;
		mn = (struct mynode *)malloc(sizeof(struct mynode));
		mn->string = (char *)malloc(sizeof(char) * 16);
		memset(mn->string, 0, 16);
		sprintf(mn->string, "%d", num);
		my_insert(&mytree, mn);
	}
	gettimeofday(&tv2, NULL);
	printf("insert %d times, elapsed time: %lu.%lu\n", 
			nums,
			tv2.tv_usec > tv1.tv_usec ? (tv2.tv_sec - tv1.tv_sec) : (tv2.tv_sec - tv1.tv_sec - 1),  // seconds.
			tv2.tv_usec > tv1.tv_usec ? (tv2.tv_usec-tv1.tv_usec) : (1000*1000 + tv2.tv_usec-tv1.tv_usec)); // microsecond.
	
	/* *delete */
	srand(time(NULL) % tv2.tv_usec);
	for(i = 0; i < nums; ++i){ // nums operation.
		int num = rand() % q2; // q2 is limitation of the id.
		key_num2[num] = 1;
		char numa[16];
		memset(numa, 0, 16);
		sprintf(numa, "%d", num);
	 	struct mynode *data = my_search(&mytree, numa);
		if (data) {
			rb_erase(&data->node, &mytree);
			my_free(data);
		}
	}
	gettimeofday(&tv3, NULL);
	printf("delete %d times, elapsed time: %lu.%lu\n", 
			nums,
			tv3.tv_usec > tv2.tv_usec ? (tv3.tv_sec - tv2.tv_sec) : (tv3.tv_sec - tv2.tv_sec - 1),  // seconds.
			tv3.tv_usec > tv2.tv_usec ? (tv3.tv_usec-tv2.tv_usec) : (1000*1000 + tv3.tv_usec-tv2.tv_usec)); // microsecond.

	printf("insert %d numbers, and then delete %d numbers, elapsed time: %lu.%lu\n", 
			nums, nums,
			tv3.tv_usec > tv1.tv_usec ? (tv3.tv_sec - tv1.tv_sec) : (tv3.tv_sec - tv1.tv_sec - 1),  // seconds.
			tv3.tv_usec > tv1.tv_usec ? (tv3.tv_usec-tv1.tv_usec) : (1000*1000 + tv3.tv_usec-tv1.tv_usec)); // microsecond.

	int same_num = 0;
	int insert_num = 0;
	int delete_num = 0;
	for(i = 0; i < q1; ++i){
		if(key_num1[i] == 1 && key_num2[i] == 1){
			same_num++;
		}
		if(key_num1[i] == 1){
			insert_num++;
		}
		if(key_num2[i] == 1){
			delete_num++;
		}
	}
	printf("in %d insert operation and %d delete operation, %d numbers is same.\n", insert_num, delete_num, same_num);
	
	return 0;
}

int test3()
{
	struct mynode *mn;
	int nums = 1000000; // number of operation.
	/* *insert */
	int i = 0;
	struct timeval tv1, tv2, tv3;
	gettimeofday(&tv1, NULL);
	for (i = 0; i < nums; i++) { // nums operation.
		mn = (struct mynode *)malloc(sizeof(struct mynode));
		mn->string = (char *)malloc(sizeof(char) * 16);
		memset(mn->string, 0, 16);
		sprintf(mn->string, "%d", i);
		my_insert(&mytree, mn);
	}
	gettimeofday(&tv2, NULL);
	printf("insert %d times, elapsed time: %lu.%lu\n", 
			nums,
			tv2.tv_usec > tv1.tv_usec ? (tv2.tv_sec - tv1.tv_sec) : (tv2.tv_sec - tv1.tv_sec - 1),  // seconds.
			tv2.tv_usec > tv1.tv_usec ? (tv2.tv_usec-tv1.tv_usec) : (1000*1000 + tv2.tv_usec-tv1.tv_usec)); // microsecond.
	
	/* *delete */
	for(i = 0; i < nums; ++i){ // nums operation.
		char numa[16];
		memset(numa, 0, 16);
		sprintf(numa, "%d", i);
	 	struct mynode *data = my_search(&mytree, numa);
		if (data) {
			rb_erase(&data->node, &mytree);
			my_free(data);
		}
	}
	gettimeofday(&tv3, NULL);
	printf("delete %d times, elapsed time: %lu.%lu\n", 
			nums,
			tv3.tv_usec > tv2.tv_usec ? (tv3.tv_sec - tv2.tv_sec) : (tv3.tv_sec - tv2.tv_sec - 1),  // seconds.
			tv3.tv_usec > tv2.tv_usec ? (tv3.tv_usec-tv2.tv_usec) : (1000*1000 + tv3.tv_usec-tv2.tv_usec)); // microsecond.

	printf("insert %d numbers, and then delete %d numbers, elapsed time: %lu.%lu\n", 
			nums, nums,
			tv3.tv_usec > tv1.tv_usec ? (tv3.tv_sec - tv1.tv_sec) : (tv3.tv_sec - tv1.tv_sec - 1),  // seconds.
			tv3.tv_usec > tv1.tv_usec ? (tv3.tv_usec-tv1.tv_usec) : (1000*1000 + tv3.tv_usec-tv1.tv_usec)); // microsecond.

	return 0;
}

int main()
{
	test3();
	return 0;
}


