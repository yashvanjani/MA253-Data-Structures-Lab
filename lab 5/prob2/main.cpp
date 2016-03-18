#include "bst.h"
#include <iostream>
using namespace std;

int main()
{
	bst t[10];
	for(int i=0;i<10;i++)
	{
		t[i].Populate(1+i);
		cout<<"Tree "<<(1+i);
		cout<<" : Min "<<t[i].TreeMinimum(t[i].root)->key;
		cout<<", Max "<<t[i].TreeMaximum(t[i].root)->key<<endl;
	}
}
