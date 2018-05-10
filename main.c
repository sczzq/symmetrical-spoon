/*************************************************************************
	> File Name: main.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 10 May 2018 10:10:09 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#include "xmalloc.h"
#include "queue.h"

int test1()
{
	IdType ids[] = {15, 12, 10, 8, 7, 9, 16, 18, 20, 17};
	TNode root = construct_tree();

	print_tree(root);

	srand(time(NULL) % getpid());

	for(int i = 0; i < sizeof(ids)/sizeof(IdType *); i++){
		printf("-------- start to add -------- \n");
		printf("%d: ", i);
//		IdType id = rand() % 20;
		IdType id = ids[i];
		printf("--id %ld\n", id);
		TNode node = (TNode)xmalloc(sizeof(*node));
		node = create_node(id, NULL, 0);
		root = add_node(root, node);
		print_tree(root);
		printf("-------- end to add -------- \n\n");
	}

	for(int i = 0; i < 20; i++){
		printf("------- start to delete --------------\n");
		IdType id = rand() % 20;
		TNode node = get_node_by_id(root, id);
		printf("find node %p, id %ld\n", node, id);
		root = delete_node(root, node);
		print_tree(root);
		printf("-------- end to delete -------------\n\n");
	}

	print_tree(root);

	deconstruct_tree(root);
}

int test2(int times)
{
	TNode root = construct_tree();
	print_tree(root);
	srand(time(NULL) % getpid());
	int q1 = 50;
	int q2 = 50;
	int t1 = 30;
	int t2 = 10;

	while(times-- > 0){
		srand(time(NULL) % getpid());
		for(int i = 0; i < t1; i++){
			printf("-------- start to add -------- \n");
			printf("%d: ", i);
			IdType id = rand() % q1;
			printf("--id %ld\n", id);
			TNode node = (TNode)xmalloc(sizeof(*node));
			node = create_node(id, NULL, 0);
			root = add_node(root, node);
			print_tree(root);
			printf("-------- end to add -------- \n\n");
		}

		for(int i = 0; i < t2; i++){
			printf("------- start to delete --------------\n");
			IdType id = rand() % q1;
			TNode node = get_node_by_id(root, id);
			printf("find node %p, id %ld\n", node, id);
			root = delete_node(root, node);
			print_tree(root);
			printf("-------- end to delete -------------\n\n");
		}
		int tree_size = get_tree_size(root);
		if(tree_size > t2){
			for(int i = 0; i < tree_size*2 - 10; i++){
				printf("------- start to delete --------------\n");
				IdType id = rand() % q1;
				TNode node = get_node_by_id(root, id);
				printf("find node %p, id %ld\n", node, id);
				root = delete_node(root, node);
				print_tree(root);
				printf("-------- end to delete -------------\n\n");
			}
		}
		sleep(1);
	}

	print_tree(root);

	deconstruct_tree(root);
}

int test3(int times)
{
	queue qu1 = get_queue();
	delete_queue(qu1);
	long long t = times;

	queue qu2 = get_queue();
	while(t-- > 0){
//		printf("----------");
		for(int i = 0; i < 2; i++){
//			printf("push %d\n", i);
			push(qu2, (void *)t);
		}
		for(int i = 0; i < 1; i++){
			long long k = (long long)pop(qu2);
//			printf("pop: %d\n", k);
		}
	}
	delete_queue(qu2);

	printf("---------------------------\n");

	t = times;
	queue qu3 = get_queue();
	while(t-- > 0){
		for(int i = 0; i < 2; i++){
//			printf("push %d\n", i);
			push(qu3, (void *)t);
		}
		for(int i = 0; i < 3; i++){
			long long k = (long long)pop(qu3);
//			printf("pop: %d\n", k);
		}
	}
	delete_queue(qu3);
}

int test4(int times)
{
	TNode root = construct_tree();
	print_tree(root);
	srand(time(NULL) % getpid());
	int q1 = 100000;
	int q2 = 50000;
	int eve_height = 0, eve_size = 0;
	int total_height = 0, total_size = 0;
	while(times-- > 0){
		srand(time(NULL) % getpid());
		printf("----------------------------------------\n");
		for(int i = 0; i < q1; i++){
//			printf("-------++++++++++++_____++++++=\n");
			IdType id = rand() % q1;
			TNode node = (TNode)xmalloc(sizeof(*node));
			node = create_node(id, NULL, 0);
			root = add_node(root, node);
			total_height += get_tree_height(root);
			total_size += get_tree_size(root);
//			printf("height: %d, size: %d\n", get_tree_height(root), get_tree_size(root));
//			print_tree(root);
		}
		for(int i = 0; i < q2; i++){
//			printf("^^^^^^^*********@@@@@@@@@@@@\n");
			IdType id = rand() % q1;
			TNode node = get_node_by_id(root, id);
			root = delete_node(root, node);
			total_height += get_tree_height(root);
			total_size += get_tree_size(root);
//			printf("height: %d, size: %d\n", get_tree_height(root), get_tree_size(root));
//			print_tree(root);
		}
		printf("----------------------------------------\n\n");
	}
	eve_height = total_height / (q1 + q2);
	eve_size = total_size / (q1 + q2);
	printf("total_height: %d, total_size: %d\n", total_height, total_size);
	printf("eve_height: %d, eve_size: %d\n", eve_height, eve_size);
	deconstruct_tree(root);
}

int test5(int times)
{
	TNode root = construct_tree();
	print_tree(root);
	srand(time(NULL) % getpid());
	int q1 = 50000;
	int q2 = 10000;
	int eve_height = 0, eve_size = 0;
	int total_height = 0, total_size = 0;
	while(times-- > 0){
		srand(time(NULL) % getpid());
		printf("----------------------------------------\n");

		for(int i = 0; i < q1; i++){
//			printf("-------++++++++++++_____++++++=\n");
			IdType id = rand() % q1;
			TNode node = (TNode)xmalloc(sizeof(*node));

			if(i % 1000 == 0)
				printf("%d\n", i);
			node = create_node(id, NULL, 0);
			root = add_node(root, node);
//			total_height += get_tree_height(root);
//			total_size += get_tree_size(root);
		}
		for(int i = 0; i < q2; i++){
			IdType id = rand() % q1;
			TNode node = get_node_by_id(root, id); // more quickly.
//			TNode node = get_node_by_id2(root, id);
			root = delete_node(root, node);
			if(i % 1000 == 0)
				printf("%d\n", i);
//			total_height += get_tree_height(root);
//			total_size += get_tree_size(root);
		}
		printf("----------------------------------------\n\n");
	}
	deconstruct_tree(root);
	eve_height = total_height / (q1 + q2);
	eve_size = total_size / (q1 + q2);
	printf("total_height: %d, total_size: %d\n", total_height, total_size);
	printf("eve_height: %d, eve_size: %d\n", eve_height, eve_size);
}

int main(int argc, const char *argv[])
{
	if(argc < 2){
		printf("usage: ./main <times>\n");
		exit(EXIT_FAILURE);
	}
	int times = atoi(argv[1]);
//	test2(times);
//	test3(times);
//	test4(times);
	test5(times);
}

