#include "bst.h"
#include <iostream>
using namespace std;

bst::bst(void) {root=NULL;}

void bst::InorderTreeWalk(node *x)
{
	if(x!=NULL)
	{
		InorderTreeWalk(x->left);
		cout<<x->key<<" "<<x->sat<<endl;
		InorderTreeWalk(x->right);
	}
}

//Implement following member functions of class bst which are declared in 'bst.h'
// TreeInsert(), TreeMinimum(), Transplant(), TreeDelete()

// write your code here
node *bst::TreeSearch(node *a, int k)
{
	if(a==NULL || k==a->key)
		return a;
	if(k<(a->key))
		return TreeSearch(a->left,k);
	else
		return TreeSearch(a->right,k);
}

node *bst::TreeMinimum(node *a)
{
	while ((a->left)!=NULL)
	{
		a=a->left;
	}
	return a;
}
node *bst::TreeMaximum(node *a)
{
	while ((a->right)!=NULL)
	{
		a=a->right;
	}
	return a;
}

void bst::Transplant(node *u, node *v)
{
	if(u->p==NULL)
		root=v;
	else if(u==u->p->left)
		u->p->left=v;
	else
		u->p->right=v;
	if(v!=NULL)
		v->p=u->p;
}

void bst::TreeInsert(node *z)
{
	node *y=NULL;
	node *x=root;
	while(x!=NULL)
	{
		y=x;
		if(z->key<x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->p=y;
	if(y==NULL)
		root=z;
	else if(z->key<y->key)
		y->left=z;
	else
		y->right=z;
}

void bst::TreeDelete(node *z)
{
	node *y;
	if(z->left==NULL)
		Transplant(z,z->right);
	else if(z->right==NULL)
		Transplant(z,z->left);
	else
	{
		y=TreeMinimum(z->right);
		if(y->p!=z)
		{
			Transplant(y,y->right);
			y->right=z->right;
			y->right->p=y;
		}
		Transplant(z,y);
		y->left=z->left;
		y->left->p=y;
	}
}