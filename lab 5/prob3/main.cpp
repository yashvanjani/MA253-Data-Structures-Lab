#include "bst.h"
#include <iostream>
using namespace std;

int main()
{
	bst t;
	t.Populate(3);
	for(int i=15;i<70;i+=5)
	{
		node *x = t.TreeSearch(t.root,i);
		if(x!=NULL)
		{
			node *s = t.TreeSuccessor(x);
			node *p = t.TreePredecessor(x);
			if(p!=NULL) cout<<"Predecessor of "<<i<<" is "<<p->key<<endl;
			if(s!=NULL) cout<<"Successor of "<<i<<" is "<<s->key<<endl;
		}
	}
}
