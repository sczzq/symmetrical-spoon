/*************************************************************************
	> File Name: set.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 12 May 2018 11:06:26 PM CST
 ************************************************************************/

/*
 * sorted set.
 * use list as its base data structure.
 * For the insert operation.
 * This implementation is adapted for insert operation.
 *
 * Note, this is not friendly for insert operation,
 * because, if make it sorted, we need to search 
 * the inserting place before to insert it into list.
 * but, the time of search operation is O(N).
 * it is lower.
 */

struct set_node{
	int id;
	struct set_node * next;
};

struct set{
	struct set_node * root;
	int number;
};

struct set * insert(struct set * set, struct set_node * node)
{
	int i = 0;
	// if set is null.
	if(set->number == 0){
		set->root = node;
		set->number = 1;
		return set;
	}
	struct set_node * set_node = set->root;
	struct set_node * cur = set->root;
	struct set_node * next = cur->next;
	// there are nodes in set.
	for( ; i < set->number; ++i){
		if(next){
			if(cur->id == node->id){
				break;
			} else if (cur->id < node->id && next->id >= node->id) {
				break;
			}
		} else {
			if((cur->id == node->id) || (cur->id < node->id) ){
				break;
			}
		}
		cur = next;
		next = cur->next;
	}
	if(set_node->id != node->id){
		if(i == 0){
			set->root = node;
			node->next = set_node;
		} else {
		}
	}
}

