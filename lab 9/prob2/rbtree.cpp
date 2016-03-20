#include "rbtree.h"

node *rbtree::TreeSearch(node *x, int k)
{
	if(x==nil || k==x->key) return x;
	if(k<x->key) return TreeSearch(x->left,k);
	else return TreeSearch(x->right,k);
}

rbtree::rbtree(void)
{
        nil = new node;
        nil->left = nil;
        nil->right = nil;
        nil->p = nil;
        nil->color = BLACK;
        root = nil;
}

//Implement the following member functions of class 'rbtree'
//	void LeftRotate(node*);
//	void RightRotate(node*);
//	void RBInsert(node*);
//	void RBInsertFixup(node*);
//	void RBTransplant(node *, node *);
//	void RBDelete(node *);
//	void RBDeleteFixup(node *);


// write your code here
