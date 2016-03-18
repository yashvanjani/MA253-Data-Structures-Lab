#include <iostream>
#include "helper.h"

//Implement 'insert()' and 'remove()' which are declared in 'helper.h'

//insert(t,k,s) should create a node containing key k and satellite data s
// (use dynamic allocation to create the node. see 'node.h' for the structure of node)
// and then insert that node into the tree t using TreeInsert()

// write your code here

//remove(t,k) should remove, from tree t,  the node whose key is k. Assume that the keys are unique.
//Find the node with key k and then use TreeDelete() to delete that node
void insert(bst& t, int k, float s)
{
	node *x= new node;
	x->p=NULL;
	x->left=NULL;
	x->right=NULL;
	x->key=k;
	x->sat=s;
	t.TreeInsert(x);
}

void remove(bst& t, int k)
{
	node *x= t.TreeSearch(t.root, k);
	if(x!=NULL)
	{
		t.TreeDelete(x);	
	}
}
