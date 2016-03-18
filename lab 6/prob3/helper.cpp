#include <iostream>
#include "helper.h"

//Implement 'insert()' which is declared in 'helper.h'

//insert(t,k,s) should create a node containing key k and satellite data s
// (use dynamic allocation to create the node. see 'node.h' for the structure of node)
// and then insert that node into the tree t using TreeInsert()

// write your code here

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

/*void remove(bst& t, int k)
{
	node *x= t.TreeSearch(t.root, k);
	if(x!=NULL)
	{
		t.TreeDelete(x);	
	}
}*/

/*void removelt(bst& t, float s)
{
	node *min=t.TreeMinimum(t.root);
	node *max=t.TreeMaximum(t.root);
	int i;
	for(i=min->key;i<=max->key;i++)
	{
		node *x=t.TreeSearch(t.root, i);
		if(x!=NULL)
		{
			if(x->sat<s)
			{
				t.TreeDelete(x);	
			}
		}
	}
}*/