#include <iostream>
#include "merge_sort.h"
using namespace std;

main()
{
	int n,i, *A;
	cout<<"How many integers to sort ?"<<endl; cin>>n;
	A = new int[n];
	for(i=0;i<n;i++) {cout<<"Enter integer #"<<i+1<<endl; cin>>A[i];}

	merge_sort(A,0,n-1);
	cout<<"Output:"<<endl;
	for(i=0;i<n;i++) cout<<A[i]<<endl;
}
