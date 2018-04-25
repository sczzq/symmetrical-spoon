
struct node{
	Node *prev;
	Node *next;
	void *data;
} Node;

Node* reverse(Node *root)
{
	Node *cur = root;
	Node *prev = NULL;
	Node *next = NULL;

	// null list or single node list, just return it.
	if(!cur || (cur && !cur->next)) return cur; 

	// move to next node.
	prev = cur;
	cur = cur->next;
	
	// Head node.
	prev->next = NULL;
	prev->prev = cur;

	// Middle node, if has one or more.
	while(cur && cur->next){
		// mark next node.
		next = cur->next;

		// replace current node's next and prev.
		cur->next = prev;
		cur->prev = next;

		// move to next node.
		prev = cur;
		cur = next;
	}

	// Tail node.
	cur->next = prev;
	cur->prev = NULL;

	return cur;
}

bool isValid(Node *root)
{
	Node *cur = root;

	// null list or single node list is valid.
	if(!cur || (cur && !cur->next)) return true; 

	// Head node.
	if(!cur->prev) return false;

	// Middle node, if has one or more.
	// FIXME: if tail->next is not null, 
	//		  then, isValid function seems no use.
	//	      more, here may cause segment fault.
	while(cur && cur->next){
		// the most check step.
		if(cur != cur->next->prev)
			return false;
		cur = cur->next;
	}

	// Tail node;
	if(!cur->next) return false;

	return true;
}
