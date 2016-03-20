#include "rbtree.h"

rbtree::rbtree(void)
{
        nil = new node;
        nil->left = nil;
        nil->right = nil;
        nil->p = nil;
        nil->color = BLACK;
        root = nil;
}

//Implement the following member functions of `rbtree` class
//	void LeftRotate(node*);
//	void RightRotate(node*);
//	void RBInsert(node*);
//	void RBInsertFixup(node*);


// write your code here

void rbtree::LeftRotate(node *x)
{
	node *y=new node;
	y=x->right;
	x->right=y->left;
	if(y->left != nil)
		y->left->p=x;
	y->p=x->p;
	if(x->p==nil)
		root=y;
	else if(x==x->p->left)
		x->p->left=y;
	else
		x->p->right=y;
	y->left=x;
	x->p=y;
}
void rbtree::RightRotate(node *x)
{
	node *y=new node;
	y=x->left;
	x->left=y->right;
	if(y->right != nil)
		y->right->p=x;
	y->p=x->p;
	if(x->p==nil)
		root=y;
	else if(x==x->p->right)
		x->p->right=y;
	else
		x->p->left=y;
	y->right=x;
	x->p=y;
}
void rbtree::RBInsert(node *z)
{
	node *y=new node;
	y=nil;
	node *x=new node;
	x=root;
	while(x!=nil)
	{
		y=x;
		if(z->key<x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->p=y;
	if(y==nil)
		root=z;
	else if(z->key<y->key)
		y->left=z;
	else
		y->right=z;
	z->left=nil;
	z->right=nil;
	z->color=RED;
	RBInsertFixup(z);
}
void rbtree::RBInsertFixup(node *z)
{
	node *y=new node;
	while(z->p->color==RED)
	{
		if(z->p==z->p->p->left)
		{
			y=z->p->p->right; //y is uncle of z
			if(y->color==RED)
			{
				z->p->color=BLACK;
				y->color=BLACK;
				z->p->p->color=RED;
				z=z->p->p;
			}
			else if(z==z->p->right)
			{
				z=z->p;
				LeftRotate(z);
			}
			z->p->color=BLACK;
			z->p->p->color=RED;
			RightRotate(z->p->p);
		}
		else
		{
			y=z->p->p->left; //y is uncle of z
			if(y->color==RED)
			{
				z->p->color=BLACK;
				y->color=BLACK;
				z->p->p->color=RED;
				z=z->p->p;
			}
			else if(z==z->p->left)
			{
				z=z->p;
				RightRotate(z);
			}
			z->p->color=BLACK;
			z->p->p->color=RED;
			LeftRotate(z->p->p);
		}
	}
	root->color=BLACK;
}