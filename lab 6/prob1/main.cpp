#include<iostream>
#include "bst.h"
#include "helper.h"

using namespace std;

int main()
{
	bst t;
	int n;
	
	cout << "Enter the number of records you want to insert" << endl;
	cin >> n;
	cout << "Enter key (int) and satellite data (float) for " << n << " records" << endl;
	for(int i=0; i<n ;i++)
	{
		int k; float s;
		cin >> k; cin >> s;
		insert(t,k,s);
	}
	cout << "Tree contains following data\n";
	t.InorderTreeWalk(t.root);

	cout << "Deleting some data\n";
	for(int k=30;k<50;k++) remove(t,k);
	cout << "After deletion, tree contains follwing data\n";
	t.InorderTreeWalk(t.root);
}
