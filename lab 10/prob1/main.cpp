#include "hash.h"
#include <iostream>

using namespace std;

main()
{
	int n,i,x,j;

	cout<<"How many keys do you want to enter ?\n";
	cin>>n;
	cout<<"n = "<<n<<endl;
	cout<<"Creating a hash table (open addressing) of size "<<n+5<<endl;
	hash ht(n+5);

	cout<<"Inserting "<<n<<" keys into the hash table\n";
	for(i=0;i<n;i++)
	{
		cin>>x; j=ht.HashInsert(x);
		cout<<"Inserted key "<<x<<" at location "<<j<<endl;
	}

	cout<<"Deleting "<<n/2<<" keys\n";
	for(i=0;i<n/2;i++)
	{
		cin>>x; j=ht.HashDelete(x);
		cout<<"Deleted key "<<x<<" from location "<<j<<endl;
	}

	cout<<"Searching keys\n";
	for(i=0;i<n/2;i++)
	{
		cin>>x;
		cout<<"Searching for key "<<x<<" : ";
		j=ht.HashDelete(x);
		if(j==NIL) cout<<"Not Found\n";
		else cout<<"found at location "<<j<<endl;
	}
}
