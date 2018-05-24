/* tree.h -- binary search tree */
/* no same item in one tree */
#ifndef __TREE_H_
#define __TREE_H_
#include <stdbool.h>

typedef struct item{
	char petname[20];
	char petkind[20];
} Item;

#define MAXITEMS 10

typedef struct node{
	Item item;
	struct node * left;
	struct node * right;
}Node;

typedef struct tree{
	Node * root;
	int size;
} Tree;

/* function prototype */ 
/* operation: initialize one tree to a null tree */
void InitializeTree(Tree * ptree);

/* operation: check tree is full or not */
bool TreeIsFull(const Tree * ptree);

/* operation: check tree is empty or not */
bool TreeIsEmpty(const Tree * ptree);

/* operation: count items number in tree */
int TreeItemCount(const Tree * ptree);

/* operation: add item to the tree */
bool AddItem(const Item * pi, Tree * ptree);

/* operation: search item in the tree */
bool InTree(const Item * pi, const Tree * ptree);

/* operation: delete the item in the tree */
bool DeleteItem(const Item * pi, Tree * ptree);

/* operation: traverse the tree and do the function on each item */
void Traverse(const Tree * ptree, void (* pfun)(Item item));

/* operation: delete all item in the tree */
void DeleteAll(Tree * ptree);

#endif

