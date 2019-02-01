#ifndef _MULTI_ROOT_TREE_
#define _MULTI_ROOT_TREE_

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Node;

class Node {
	public:
		Node(char cc)
			: c{cc},
			  single{false}
		{
		};

		~Node(){ };
/*
		bool operator==(const Node &n2)	{ return c == (n2.c); };
		bool operator!=(const Node &n2)	{ return c != (n2.c); };
		bool operator<(const Node &n2)	{ return c < (n2.c); };
		bool operator>(const Node &n2)	{ return c > (n2.c); };
*/
		bool operator==(const Node n2)	{ return c == (n2.c); };
		bool operator!=(const Node n2)	{ return c != (n2.c); };
		bool operator<(const Node n2)	{ return c < (n2.c); };
		bool operator>(const Node n2)	{ return c > (n2.c); };

		char c;
		// current node is the identifier.
		// means all of its children just have child.
		bool single;
		vector<Node> children;
};

class MultiRootTree {
	public:
		MultiRootTree() { };
		~MultiRootTree() {  };

		int Push(string const &s);

		int Push(const vector<string> &vs);

		string GetIdentifier(const string s);

		vector<string> GetIdentifiers();

		vector<string> Strings();

	private:
		int UpdateTree();

		bool DepthTraverse2(vector<Node>::iterator root);
		vector<string> DepthTraverse(const vector<Node>::iterator &root, bool );

		vector<Node> roots;
};

#endif

