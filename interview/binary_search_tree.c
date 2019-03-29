// binary search tree optor
//
// insert 
// delete
// search
// tranvese
//
// height

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "header.h"

typedef struct Node Node;
typedef struct BinarySearchTree BinarySearchTree;
typedef int (*Compare)(void *, void *);

void insertNode(Node *node, void *data, Compare compare);
void insertLeft(Node *node, void *data, Compare compare);
void insertRight(Node *node, void *data, Compare compare);

struct Node {
	void *data;
	Node *left;
	Node *right;
	int mark;
};

struct BinarySearchTree {
	Node *root;
	Compare compare;
};

// return value
//	-1 s1 less than s2
//	0  s1 equals to s2
//	1  s1 greater than s2
int string_compare(void *s1, void *s2)
{
	return strcmp((char *)s1, (char *)s2);
}

int integer_compare(void *s1, void *s2)
{
	return ((*(int *)s1 - *(int *)s2)) % 1;
}

Node *getNode(void *data)
{
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->mark = 0;
	return node;
}

void releaseNode(Node *node)
{
	if(node)
	{
		if (node->left)
		{
			releaseNode(node->left);
			node->left = NULL;
		}
		if (node->right)
		{
			releaseNode(node->right);
			node->right = NULL;
		}
		node->data = NULL;
		node->mark = 0;
		free(node);
	}
}

BinarySearchTree *getBSTree(Compare comp)
{
	BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
	tree->root = getNode(NULL);
	tree->compare = comp;
	return tree;
}

void releaseBSTree(BinarySearchTree *tree)
{
	Node *root = tree->root;
	releaseNode(root);
	tree->root = NULL;
	tree->compare = NULL;
	free(tree);
}

void insertNode(Node *node, void *data, Compare compare)
{
	int cmp = compare(data,node->data);
	if (cmp < 0) {
		insertLeft(node, data, compare);
	} else if (cmp == 0) {
		// do nothing
	} else if (cmp > 0) {
		insertRight(node, data, compare);
	}
}

void insertLeft(Node *node, void *data, Compare compare)
{
	if (!node->left)
	{
		node->left = getNode(data);
		return;
	}
	insertNode(node->left, data, compare);
}

void insertRight(Node *node, void *data, Compare compare)
{
	if (!node->right) 
	{
		node->right = getNode(data);
		return;
	}
	insertNode(node->right, data, compare);
}

void bst_insert(BinarySearchTree *tree, void *data)
{
	Node *node = tree->root;
	if (!node->data)
	{
		node->data = data;
		return;
	}
	insertNode(node, data, tree->compare);
}

Node *searchNode(Node *node, void *data, Compare compare)
{
	Node *n = node;
	while(n)
	{
		int cmp = compare(data, n->data);
		if (cmp < 0){
			n = n->left;
		} else if (cmp == 0) {
			return n;
		} else if (cmp > 0) {
			n = n->right;
		}
	}
	return NULL;
}

Node *bst_search(BinarySearchTree *tree, void *data)
{
	Node *node = tree->root;
	if (!node)
	{
		return NULL;
	}
	return searchNode(node, data, tree->compare);
}

int searchParentAndCur(BinarySearchTree *tree, 
		void *data,
		Node **parent,
		Node **cur)
{
	Node *node = tree->root;
	int cmp = tree->compare(data, node->data);
	int lasrcmp = cmp;
	if (cmp == 0)
	{
		*parent = NULL;
		*cur = node;
		return 0;
	}
	while(node)
	{
		lastcmp = cmp;
		*parent = node;
		if (lastcmp < 0) {
			if (node->left)
				cmp = tree->compare(data, node->left->data);
			node = node->left;
		} else {
			if (node->right)
				cmp = tree->compare(data, node->right->data);
			node = node->right;
		}
		if (cmp == 0)
		{
			if (lastcmp < 0)
				*cur = node->left;
			else
				*cur = node->right;
		}
	}
	return 0;
}

Node *findRightest(Node *node)
{
	while(node && node->right)
	{
		node = node->right;
	}
	return node;
}

int deleteRightChild(Node *parent, Node *child)
{
	if (child->left)
	{
		parent->right = child->left;
		Node *node = findRightest(child->left);
		node->right = child->right;
	}
	else
	{
		parent->right = child->right;
	}
	child->left = NULL;
	child->right = NULL;
	releaseNode(child);
	return 0;
}

int deleteLeftChild(Node *parent, Node *child)
{
	if (child->left)
	{
		parent->left = child->left;
		Node *node = findRightest(child->left);
		node->right = child->right;
	}
	else
	{
		parent->left = child->right;
	}
	child->left = NULL;
	child->right = NULL;
	releaseNode(child);
	return 0;
}

int bst_delete(BinarySearchTree *tree, void *data)
{
	Node *node = tree->root;
	Node *parent = NULL, *match = NULL;

	searchParentAndCur(node, data, &parent, &match);
	// match is root
	if(!parent && match)
	{
		if (match->left)
		{
			tree->root = match->left;
			node = findRightest(match->left);
			node->right = match->right;
		}
		else 
		{
			tree->root = match->right;
		}
		match->left = NULL;
		match->right = NULL;
		releaseNode(match);
	}
	// match is not root
	else if(parent && match)
	{
		if (parent->left == match)
		{
			deleteLeftChild(parent, match);
		}
		else
		{
			deleteRightChild(parent, match);
		}
	}

	return NULL;
}

int node_stack(Node *node, Stack *stack)
{
	if (!node)
		return 0;

	void *null;
	stack_push(stack, node);
	int max_size = 0;
	int stacksize = stack_size(stack);
	Node *root = node;
	node->mark = 1;
	while(stacksize > 0)
	{
		printf("node: %s\n", (char *)node->data);
		if (max_size < stacksize)
		{
			max_size = stacksize;
		}

		if (node->left && !node->left->mark)
		{
			printf("in left\n");
			stack_push(stack, node->left);
			node->left->mark = 1;
		}
		else if (node->right && !node->right->mark)
		{
			printf("in right\n");
//			stack_pop(stack, (void **)&null);
			stack_push(stack, node->right);
			node->right->mark = 1;
		}
		else
		{
			printf("in pop\n");
			stack_pop(stack, (void **) &null);
		}
		stack_access(stack, (void **) &node);
		stacksize = stack_size(stack);
	}
	return max_size;
}

int bst_height(BinarySearchTree *tree)
{
	Node *node = tree->root;
	Stack *stack = getStack();
	int h = node_stack(node, stack); 
	releaseStack(stack);
	return h;
}

int bst_test1()
{
	BinarySearchTree *tree = getBSTree(string_compare);
	char *s1 = "hello";
	char *s2 = "world";
	char *s3 = "hi";
	char *s4 = "whole";
	char *s5 = "hea";
	char *s6 = "ha";
	char *s7 = "hab";

	insert(tree, (void *)s1);
	insert(tree, (void *)s2);
	insert(tree, (void *)s3);
	insert(tree, (void *)s4);
	insert(tree, (void *)s5);
	insert(tree, (void *)s6);
	insert(tree, (void *)s7);

	printf("height: %d\n", bst_height(tree));

	Node *n = bst_search(tree, s2);
	printf("%s\n", (char *)n->data);

	releaseBSTree(tree);
}

int main()
{
	bst_test1();
}

