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
void rbtree::RBTransplant(node *u, node *v)
{
	if(u->p==nil)
		root=v;
	else if(u==u->p->left)
		u->p->left=v;
	else
		u->p->right=v;
	v->p=u->p;
}

void rbtree::RBDelete(node *z)
{
	node *y=new node;
	node *x=new node;
	y=z;
	rbcol y_original_color=y->color;
	if(z->left==nil)
	{
		x=z->right;
		RBTransplant(z,z->right);
	}
	else if(z->right==nil)
	{
		x=z->left;
		RBTransplant(z,z->left);
	}
	else
	{
		y=TreeMinimum(z->right);
		y_original_color=y->color;
		x=y->right;
		if(y->p==z)
		{
			x->p=y;
		}
		else
		{
			RBTransplant(y,y->right);
			y->right=z->right;
			y->right->p=y;
		}
		RBTransplant(z,y);
		y->left=z->left;
		y->left->p=y;
		y->color=z->color;
	}
	if(y_original_color==BLACK)
		RBDeleteFixup(x);
}

void rbtree::RBDeleteFixup(node *x)
{
	node *w=new node;
	while(x!=root && x->color==BLACK)
	{
		if(x==x->p->left)
		{
			w=x->p->right;
			if(w->color==RED)
			{
				w->color=BLACK;
				x->p->color=RED;
				LeftRotate(x->p);
				w=x->p->right;
			}
			if(w->left->color==BLACK && w->right->color==BLACK)
			{
				w->color=RED;
				x=x->p;
			}
			else
			{
				if(w->right->color==BLACK)
				{
					w->left->color=BLACK;
					w->color=RED;
					RightRotate(w);
					w=x->p->right;
				}
				w->color=x->p->color;
				x->p->color=BLACK;
				w->right->color=BLACK;
				LeftRotate(x->p);
				x=root;
			}
		}
		else
		{
			w=x->p->left;
			if(w->color==RED)
			{
				w->color=BLACK;
				x->p->color=RED;
				RightRotate(x->p);
				w=x->p->left;
			}
			if(w->right->color==BLACK && w->left->color==BLACK)
			{
				w->color=RED;
				x=x->p;
			}
			else
			{
				if(w->left->color==BLACK)
				{
					w->right->color=BLACK;
					w->color=RED;
					LeftRotate(w);
					w=x->p->left;
				}
				w->color=x->p->color;
				x->p->color=BLACK;
				w->left->color=BLACK;
				RightRotate(x->p);
				x=root;
			}
		}
	}
	x->color=BLACK;
}

node *rbtree::TreeMinimum(node *a)
{

	while ((a->left)!=nil)
	{
		a=a->left;
	}
	return a;
}

void rbtree::LeftRotate(node *x)
	{
		node *y= x->right;
		x->right = y->left;
		if(y->left != nil) y->left->p = x;
		y->p = x->p;
		if(x->p == nil) root =y;
		else 	{
				if(x == x->p->left) x->p->left = y;
				else x->p->right = y;			
			}
		y->left = x;
		x->p = y;
	}

void rbtree::RightRotate(node *x)
	{
		node *y= x->left;
		x->left = y->right;
		if(y->right != nil) y->right->p = x;
		y->p = x->p;
		if(x->p == nil) root =y;
		else 	{
				if(x == x->p->left) x->p->left = y;
				else x->p->right = y;			
			}
		y->right = x;
		x->p = y;
	}

void rbtree::RBInsert(node *x)
	{
		node *y=nil;
		node *z=root;
		while(z!=nil)
			{
				y=z;
				if(x->key < z->key) z=z->left;
				else z=z->right;				
			}
		x->p=y;
		if(y==nil) root =x;
		else	{
				if(x->key < y->key) y->left = x;
				else y->right = x;
			}
		x->left=nil;
		x->right=nil;
		x->color=RED;
		RBInsertFixup(x);
	}

void rbtree::RBInsertFixup(node *z)
	{	node *y;
		while(z->p->color ==RED)
			{
				if(z->p == z->p->p->left) 
					{	y= z->p->p->right;
						if(y->color ==RED)
						{
							z->p->color = BLACK;
							y->color = BLACK;
							z->p->p->color = RED;
							z=z->p->p;
						}
						else    { if(z==z->p->right) {z=z->p; LeftRotate(z);}
							z->p->color = BLACK;
							z->p->p->color = RED;
							RightRotate(z->p->p);	
							}
					}
				
				else 	{
						y=z->p->p->left;
						if(y->color ==RED)
						{
							z->p->color = BLACK;
							y->color = BLACK;
							z->p->p->color = RED;
							z=z->p->p;
						}
						else    { if(z==z->p->left) {z=z->p; RightRotate(z);}
							z->p->color = BLACK;
							z->p->p->color = RED;
							LeftRotate(z->p->p);	
							}
					}			
			}
		root->color = BLACK;
	}