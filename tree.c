/*************************************************************************
	> File Name: tree.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 09 May 2018 05:03:09 PM CST
 ************************************************************************/

#include <string.h> // memcmp
#include <stdio.h> // fprintf printf
#include <stdlib.h> // malloc free
#include "queue.h"
#include "tree.h"
#include "xmalloc.h"

TNode create_node(IdType id, void *data, int data_size)
{
	TNode node = xmalloc(sizeof(*node));
	node->id = id;
	node->data = data;
	node->data_size = data_size;
	node->left = NULL;
	node->right = NULL;
	return node;
}

TNode construct_tree(void)
{
	return NULL;
}

int deconstruct_tree(TNode root)
{
	if(root){
		deconstruct_tree(root->left);
		deconstruct_tree(root->right);
		free_node(root);
	}
	return 0;
}

TNode add_node(TNode root, TNode node)
{
	if(root && node){
		if(node->id > root->id){
			if(root->right){
				root->right = add_node(root->right, node);
			} else {
				root->right = node;
			}
		} else if(node->id < root->id){
			if(root->left) {
				root->left = add_node(root->left, node);
			} else {
				root->left = node;
			}
		} else {
			void *data = root->data;
			root->data = node->data;
			root->data_size = node->data_size;
			free(data);
		}
	}
	if(!root && node)
		return node;
	return root;
}

TNode get_node(TNode root, void *data)
{
	TNode node = NULL;
	if(root){
		if(0 == memcmp(root->data, data, root->data_size)){
			return root;
		} else {
			if(root->left){
				node = get_node(root->left, data);
			}
			if(!node && root->right){
				node = get_node(root->right, data);
			}
		}
	}
	return node;
}

TNode get_node_by_id2(TNode root, IdType id)
{
	TNode node = NULL;
	queue qu = get_queue();
	if(root){
		push(qu, (void*)root);
	}
	while(!isempty(qu)){
		TNode nn = (TNode)pop(qu);
		if(nn->id == id){
			node = nn;
			break;
		}
		if(nn->left){
			push(qu,(void *)nn->left);
		}
		if(nn->right){
			push(qu,(void *)nn->right);
		}
	}

	delete_queue(qu);

	return node;
}

TNode get_node_by_id(TNode root, IdType id)
{
	TNode node = NULL;
	if(root){
		if(root->id == id){
			return root;
		} else {
			if(root->left){
				node = get_node_by_id(root->left, id);
			}
			if(!node && root->right){
				node = get_node_by_id(root->right, id);
			}
		}
	}
	return node;
}

TNode change_node(TNode root, IdType id, void *new_data)
{
	TNode node = get_node_by_id(root, id);
	void *old_data = node->data;
	node->data = new_data;
	free(old_data);
	return NULL;
}

TNode find_rightest(TNode root)
{
//	if(root){
//		printf("node id %ld, ", root->id);
//	}
	while(root && root->right){
		root = root->right;
	}
//	if(root){
//		printf("its rightest node id %ld.\n", root->id);
//	}
	return root;
}

TNode find_leftest(TNode root)
{
	while(root && root->left){
		root = root->left;
	}
	return root;
}

TNode find_righter(TNode root)
{
//	if(root){
//		printf("node id %ld, ", root->id);
//	}
	while(root && root->right && root->right->right){
		root = root->right;
	}
//	if(root){
//		printf("its righter node id %ld.\n", root->id);
//	}
	return root;
}

TNode find_lefter(TNode root)
{
	while(root && root->left && root->left->left){
		root = root->left;
	}
	return root;
}

int free_node(TNode node)
{
	if(node){
//		printf("free node id %ld\n", node->id);
		if(node->data){
			free(node->data);
		}
		free(node);
	}
	return 0;
}

TNode find_parent(TNode root, TNode node)
{
	if(root && node){
		if(root->id == node->id){
//			printf("node id %ld, its parent id %ld\n", node->id, root->id);
			return root;
		}
		if(root->left && root->left->id == node->id){
//			printf("node id %ld, its parent id %ld\n", node->id, root->id);
			return root;
		}
		if(root->right && root->right->id == node->id){
//			printf("node id %ld, its parent id %ld\n", node->id, root->id);
			return root;
		}
		TNode parent = find_parent(root->left, node);
		if(parent){
			return parent;
		} else {
			return find_parent(root->right, node);
		}
	}
	return NULL;
}

TNode delete_node(TNode root, TNode node)
{
	if(node && root){
		if(root != node){
			TNode parent = find_parent(root, node);
			if(parent){
				if(parent->left == node){
					parent->left = delete_root(node);
				} else if(parent->right == node){
					parent->right = delete_root(node);
				}
			}
		} else {
			root = delete_root(root);
		}
	}
	return root;
}

TNode delete_root(TNode root)
{
	TNode pr = root;
	if(pr){
		TNode newroot = NULL;
		newroot = find_rightest(pr->left); 
		if(newroot) {
			root = newroot;
			TNode newrootparent = find_righter(pr->left);
			if(newrootparent != newroot){
				newrootparent->right = newroot->left;
			}
			if(newroot != pr->left){
				newroot->left = pr->left;
			}
			newroot->right = pr->right;
		} else {
			root = pr->right;;
		}
		free_node(pr);
	}

	return root;
}

TNode sort_tree(TNode root)
{
	printf("unused\n");
	return NULL;
}

TNode balance_tree(TNode root)
{
	printf("unused\n");
	return NULL;
}

int get_tree_height(TNode root)
{
	int height = 0;
	if(root){
		if(root->left || root->right){
			++height;
		}
		int left_height = 0;
		int right_height = 0;
		left_height = get_tree_height(root->left);
		right_height = get_tree_height(root->right);
		if(left_height > right_height){
			height += left_height;
		} else {
			height += right_height;
		}
//		printf("node id %ld, height: %d\n", root->id, height);
	}
	return height;
}

int get_tree_size(TNode root)
{
	int size = 0;
	queue qu = get_queue();
	if(root){
		push(qu, (void *)root);
		++size;
	}
	while(!isempty(qu)){
		root = (TNode)pop(qu);
		if(root->left){
			++size;
			push(qu, (void *)root->left);
		}
		if(root->right){
			++size;
			push(qu, (void *)root->right);
		}
	}
//	printf("tree size %d\n", size);
	delete_queue(qu);
	return size;
}

int print_tree(TNode root)
{
	int height = get_tree_height(root);
	int size = get_tree_size(root);
	printf("tree height: %d\n", height);
	queue qu = get_queue();
	if(root){
		push(qu, (void *)root);
	}
	while(!isempty(qu)){
		root = (TNode)pop(qu);
		if(root->left){
			printf("%ld -> left %ld\n", root->id, root->left->id);
			push(qu, (void *)root->left);
		}
		if(root->right){
			printf("%ld -> right %ld\n", root->id, root->right->id);
			push(qu, (void *)root->right);
		}
		if(!root->left && !root->right){
			printf("%ld leaf\n", root->id);
		}
	}
	delete_queue(qu);
	return 0;
}

/*
 * output format: 
 *	height:size:1-left-2:1-right-3:...
 *	6:3:1-left-2:1-right-3:3-leaf:...
 */
int print_to_string(char *str, int str_len, TNode root)
{
	int height = get_tree_height(root);
	int size = get_tree_size(root);
	str[0] = 0;
	snprintf(str + strlen(str), str_len, "%d:", height);
	snprintf(str + strlen(str), str_len - strlen(str), "%d:", size);
	queue qu = get_queue();
	if(root){
		push(qu, (void *)root);
	}
	while(!isempty(qu)){
		root = (TNode) pop(qu);
		if(root->left){
			snprintf(str+strlen(str), str_len - strlen(str), "%ld-left-%ld:", root->id, root->left->id);
			push(qu, (void *)root->left);
		}
		if(root->right){
			snprintf(str+strlen(str), str_len - strlen(str), "%ld-right-%ld:", root->id, root->right->id);
			push(qu, (void *)root->right);
		}
		if(!root->left && !root->right){
			snprintf(str+strlen(str), str_len - strlen(str), "%ld-leaf:", root->id);
		}
	}
	return 0;
}


