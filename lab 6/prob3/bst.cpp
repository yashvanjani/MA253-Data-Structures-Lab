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
// TreeInsert() , Size() , Height()

// write your code here
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

int bst::Size(node *x)
{
	if(x==NULL)
		return(0);
	else
		return(1+Size(x->left)+Size(x->right));
}

int bst::Height(node *x)
{
	int height, max_height;
	if(x==NULL)
		return(-1);
	else if(x->left==NULL && x->right==NULL)
		return(0);
	else
	{
		height=0;
		int a=Height(x->left);
		int b=Height(x->right);
		if(a<=b)
			return(1+b);
		else
			return(1+a);

	}
}