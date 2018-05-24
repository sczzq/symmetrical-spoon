/*************************************************************************
	> File Name: tree.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 10 May 2018 10:02:56 AM CST
 ************************************************************************/

#ifndef TREE_H_
#define TREE_H_
/*
 * Implementation of btree.
 * supported operator:
 *	construct a tree,
 *	deconstruct a tree,
 *	create node from data, 
 *	add node to a tree,
 *	delete node from a tree,
 *	get a node from a tree,
 *	change data of a node,
 *
 *	get height of a tree.
 *	balance the height of a tree.
 *	sort a tree.
 *
 */

typedef long long IdType;

struct Node {
	IdType id;
	void *data;
	int data_size;

	struct Node *left;
	struct Node *right;
	struct Node *parent;
};

typedef struct Node * TNode;

/*
 * construct a null tree.
 * return the root node.
 */
TNode construct_tree(void);

/*
 * deconstruct a tree.
 * return the result.
 */
int deconstruct_tree(TNode root);

/*
 * create a node from data.
 */
TNode create_node(IdType id, void *data, int data_size);

/*
 * add a node to a tree.
 */
TNode add_node(TNode root, TNode node);

/*
 * get a node from a tree by its data.
 */
TNode get_node(TNode root, void *data);

TNode get_node_by_id(TNode root, IdType id);

TNode get_node_by_id2(TNode root, IdType id);

/*
 * change a node from a tree by id to new_data.
 */
TNode change_node(TNode root, IdType id, void *new_data);

/*
 * delete a node from a tree by id.
 * param:
 *	root	Root node of the tree.
 *	id	Node id to delete.
 */
TNode delete_node(TNode root, TNode node);
TNode delete_root(TNode root);

TNode sort_tree(TNode root);

TNode balance_tree(TNode root);

int get_tree_height(TNode root);

int get_tree_size(TNode root);

TNode find_rightest(TNode root);
TNode find_leftest(TNode root);
TNode find_righter(TNode root);
TNode find_lefter(TNode root);

TNode find_parent(TNode root, TNode node);
int free_node(TNode node);

int print_tree(TNode root);

#endif
