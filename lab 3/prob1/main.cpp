#include <iostream>
#include "qsort.h"

using namespace std;

int main()
{
	int n;
	cout<<"Enter the number of integers"<<endl;
	cin>>n;
	
	int *A = new int[n];

	for(int i=0;i<n;i++)
	{
		cout<<"Enter integer #"<<i+1<<endl;
		cin>>A[i];
	}

	quicksort(A,0,n-1);

	cout<<"Sorted Output:"<<endl;
	for(int i=0;i<n;i++) cout<<A[i]<<endl;

	return 0;
}

