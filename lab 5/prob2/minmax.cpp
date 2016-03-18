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

//Implement TreeMinimum() and TreeMaximum()
// as declared in 'bst.h' 
// write your code here

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
