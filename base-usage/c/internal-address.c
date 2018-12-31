/*************************************************************************
    > File Name: internal-address.c
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年12月30日 星期日 17时03分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/*
 * net address, ipv4
 * need about 4GB RAM
 * more than 4GB
 *
 * use B-tree to index.
 * one node has 256 + sizeof(void *) byte
 * total node number is
 *     256 + 256*256 + 256*256*256 + 256*256*256*256 bytes
 * this memory region should be heap.
 */

struct address_node{
	unsigned char data[256];
	struct address_node *next;
};

struct address_table{
	struct address_node *root;
	int version;
};

int assign_node(struct address_node *node, int maxchar, int isleaf)
{
	unsigned char i = 0;
	for(i = 0; i < maxchar; i++)
	{
		node->data[i] = i;
		if (i == maxchar - 1)
			break;
	}
	if (!isleaf)
	{
		node->next = malloc(sizeof(struct address_node) * maxchar);
		if (node->next == NULL) {
			printf("malloc error\n");
			exit(1);
		}
	} else {
		node->next = NULL;
	}
	return 0;
}

int init_address_table()
{
	struct address_table table;
	table.version = 4;
	table.root = malloc(sizeof(struct address_node));
	if (table.root == NULL) {
		printf("malloc error\n");
		exit(1);
	}
	int maxchar = 256;
	int i = 0;
	printf ("assign first level\n");
	assign_node(table.root, maxchar, 0);
	struct address_node *node;
	for (i = 0; i < maxchar; i++) {
		if (i == 0)
			printf ("assign second level\n");
		node = (table.root->next) + i;
		assign_node(node, maxchar, 0);
		struct address_node *lnode;
		int j = 0;
		for (j = 0; j< maxchar; j++) {
			lnode = node->next + j;
			// assign three level.
			assign_node(lnode, maxchar, 0);
			struct address_node *fnode;
			int k = 0;
			for(k = 0; k < maxchar; k++) {
				fnode = lnode->next + k;
				assign_node(fnode, maxchar, 1);
			}
		}
	}
}

int main()
{
	init_address_table();

	char c = getchar();
}
