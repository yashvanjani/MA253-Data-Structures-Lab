#include "bst.h"
#include <iostream>
using namespace std;

void bst::InorderTreeWalk(node *x)
{
	if(x!=NULL)
	{
		InorderTreeWalk(x->left);
		cout<<x->key<<" "<<x->sat<<endl;
		InorderTreeWalk(x->right);
	}
}


//Implement TreeSearch(), TreeMinimum(), TreeMaximum()
// , TreePrdecessor() and TreeSuccessor() as declared in 'bst.h'
//In prob1 and prob2 you have already written code for
//   TreeSearch(), TreeMinimum() and  TreeMaximum()
//You need to write that code again here. 
// write your code here
node *bst::TreeSuccessor(node *x)
{
	if(x->right!=NULL)
		return TreeMinimum(x->right);
	node *y=x->p;
	while(y!=NULL && x==y->right)
	{
		x=y;
		y=y->p;
	}
	return y;
}

node *bst::TreePredecessor(node *x)
{
	if(x->left!=NULL)
		return TreeMaximum(x->left);
	node *y=x->p;
	while(y!=NULL && x==y->left)
	{
		x=y;
		y=y->p;
	}
	return y;
}



node *bst::TreeSearch(node *a, int k)
{
	if(a==NULL || k==a->key)
		return a;
	if(k<(a->key))
		return TreeSearch(a->left,k);
	else
		return TreeSearch(a->right,k);
}

node *bst::IterativeTreeSearch(node *a, int k)
{
	while(a!=NULL && k!=a->key)
	{
		if(k<(a->key))
			a=a->left;
		else
			a=a->right;
	}
	return a;
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