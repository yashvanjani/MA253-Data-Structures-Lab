#include <iostream>
#include "rbtree.h"
#include "other.h"
using namespace std;

int main()
{
	rbtree t;
	node *x;
	int n;
	cout<<"Enter the number on integers to insert"<<endl;
	cin>>n;
	cout<<"Enter "<<n<<" integers"<<endl;
	for(int i=0;i<n;i++)
	{
		x = new node;
		cin>>x->key;
		t.RBInsert(x);
	}
	
	cout<<"The Red-Black Tree has the following structure"<<endl;
	t.show(t.root);
	draw(t);
	return 0;
}
