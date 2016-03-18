#include "bst.h"
#include <iostream>
using namespace std;

void f(node *n)
{
	if(n==NULL) cout<<"Not Found";
	else cout<<"("<<n->key<<","<<n->sat<<")";
}

int main()
{
	bst t1,t2;
	t1.Populate(1);
	t2.Populate(2);
	cout<<"Two trees with random data are created\n";
	cout<<"Enter key (between 10-70) to search. Enter 0 to exist\n";
	int k;
	while(true)
	{
		cin>>k;
		if(k==0) break;
		cout<<"key: "<<k<<"\tTree1 ";f(t1.TreeSearch(t1.root,k));
		cout<<"\tTree2 ";f(t2.TreeSearch(t2.root,k));
		cout<<endl;
	}
}
