// Find shortest unique prefix to represent each word.

// start time 21:47
// need time 44 minutes
// end time is 23:04
// real time is 1:20, 80 minutes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
	char c;
	int users;
	Node **childs;
	int size;
	int capability;
};


Node *getNode(char c)
{
	Node *node = malloc(sizeof(Node));
	node->c = c;
	node->users = 1;
	node->childs = malloc(sizeof(void *) * 8);
	node->size = 0;
	node->capability = 8;
	return node;
}

void releaseNode(Node *node)
{
	if (node)
	{
		for(int i = 0; i < node->size; i++)
		{
			releaseNode(node->childs[i]);
		}
		node->c = 0;
		node->users = 0;
		node->size = 0;
		free(node->childs);
		node->capability = 0;
		free(node);
	}
}

Node *getNullRoot()
{
	return getNode(0);
}

Node *nodeRealloc(Node *node)
{
	if (node->size + 1 >= node->capability)
	{
		node->capability *= 2;
		node->childs = realloc(node->childs,
				node->capability * sizeof(void *));
	}
	return node;
}

Node *insertChar(Node* node, char c)
{
	for(int i = 0; i < node->size; i++)
	{
		if (node->childs[i]->c == c)
		{
			node->childs[i]->users++;
//			printf("%c child is in\n", c);
			return node->childs[i];
		}
	}
	Node *newnode = getNode(c);
	nodeRealloc(node);
	node->childs[node->size++] = newnode;
//	printf("%c get new child\n", c);
	return newnode;
}

void insertString(Node *node, const char *s)
{
	Node *cnode = node;
	while(*s)
	{
		cnode = insertChar(cnode, *s);
//		printf("%c %d ", *s, cnode->size);
		s += 1;
	}
}

Node *findOnlyone(Node *node, int num)
{
	for (int i = 0; i < node->size; i++)
	{
		if (node->childs[i]->users == num)
			return node->childs[i];
	}
	return NULL;
}

void transfer(Node *node)
{
	printf("%c %d %d\n", node->c, node->size, node->users);
	for(int i = 0; i < node->size; i++)
	{
		transfer(node->childs[i]);
	}
}

int find_shortest_unique_prefix(const char *strings[], int num, char **prefix)
{
	Node *node = getNullRoot();
	int max_len = 1;
	for (int i = 0; i < num; i++)
	{
		const char *s = strings[i];
		if (max_len < strlen(s))
		{
			max_len = strlen(s);
		}
		insertString(node, s);
		printf("%d:[%s]\n", i, s);
	}
	char *cp = malloc(max_len);
	memset(cp, 0, max_len);
	int index = 0;
	Node *n = findOnlyone(node, num);
//	transfer(node);
	while(n)
	{
		cp[index++] = n->c;
		n = findOnlyone(n, num);
	}
	printf("unique prefix:");
	printf("[%s]\n", cp);
	releaseNode(node);
	free(cp);
}

int main()
{
	const char *strings[] = {"hello", "he", "hell", NULL};
	find_shortest_unique_prefix(strings, 3, NULL);

	const char *strings2[] = {"hello", "he", "hell", "world", NULL};
	find_shortest_unique_prefix(strings2, 4, NULL);

	const char *strings3[] = {"hello", "he", "hell", "heaaa", NULL};
	find_shortest_unique_prefix(strings3, 4, NULL);
}

