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

//Implement TreeSearch() as declared in 'bst.h'
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