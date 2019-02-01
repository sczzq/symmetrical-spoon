#include "multiroottree.h"

int MultiRootTree::Push(string const &s)
{
	vector<Node> * css = &roots;
	for (auto c : s)
	{
		Node node{c};
		unsigned int i = 0;
		for (i = 0; i < css->size(); i++)
		{
			if (node == (*css)[i])
			{
				break;
			}
		}

		if (i == css->size())
		{
			css->push_back(node);
			css = &((*css)[css->size()-1].children);
		}
		else
		{
			css = &((*css)[i].children);
		}
	}
	return 0;
}

int MultiRootTree::Push(const vector<string> &vs)
{
	for (int i = 0; i < vs.size(); i++)
	{
		Push(vs[i]);
	}

	UpdateTree();

	return 0;
}

string MultiRootTree::GetIdentifier(const string s)
{
	return s;
}

vector<string> MultiRootTree::GetIdentifiers()
{
	vector<string> vs;

	vector<Node>::iterator it = roots.begin();
	for (; it != roots.end(); it++)
	{
		vector<string> cvs = DepthTraverse(it, true);
		vs.insert(vs.end(), cvs.begin(), cvs.end());
	}

	return vs;
}

int MultiRootTree::UpdateTree()
{
	vector<Node>::iterator it = roots.begin();
	for (; it != roots.end(); it++)
	{
		DepthTraverse2(it);
	}

	return 0;
}

// node.single default is false.
bool MultiRootTree::DepthTraverse2(vector<Node>::iterator root)
{
	if (root->children.size() == 0)
	{
		root->single = true;
		return root->single;
	}

	vector<Node>::iterator it = root->children.begin();
	for ( ; it != root->children.end(); it++)
	{
		DepthTraverse2(it);
	}

	// until here, all children of root are updated.

	if (root->children.size() == 1)
	{
		root->single = root->children[0].single;
	}

	// default is false;
//	else if (root->children.size() > 1)
//		root->single = false;

	return root->single;
}

vector<string> MultiRootTree::Strings()
{
	vector<string> vs;
	vector<Node>::iterator it = roots.begin();
	for (; it != roots.end(); it++)
	{
		vector<string> cvs = DepthTraverse(it, false);
		vs.insert(vs.end(), cvs.begin(), cvs.end());
	}
	return vs;
}

vector<string> MultiRootTree::DepthTraverse(const vector<Node>::iterator &root, bool single_check)
{
	vector<string> vs;
	if (root->children.size() == 0)
	{
		string s {root->c};
		vs.push_back(s);
		return vs;
	}

	vector<Node>::iterator it = root->children.begin();
	for ( ; it != root->children.end(); it++)
	{
		if (!single_check || it->single == false)
		{
			vector<string> cvs = DepthTraverse(it, single_check);
			vs.insert(vs.end(), cvs.begin(), cvs.end());
		}
		else if (single_check && it->single == true )
		{
			string s {it->c};
			vs.push_back(s);
		}
	}
	for (auto &s : vs)
	{
		s = root->c + s;
	}

	return vs;
}


