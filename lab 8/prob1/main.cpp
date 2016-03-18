#include <iostream>
#include <cstdlib>
#include "heap.h"
using namespace std;

int main()
{
	int n;
	cout<<"How many integers do you want to enter ?"<<endl;
	cin>>n;
	heap h(n);
	cout<<"Enter "<<n<<" integers"<<endl;

	int i;
	for(i=0;i<h.length;i++) cin>>h.A[i];
	cout<<"Heap now contains "<<n<<" integers in random order\n";

	cout<<"Calling BuildMinHeap()\n";
	h.BuildMinHeap();
	cout<<"Checking Min-Heap property\n";
	for(i=1;i<n;i++)
		if(h.A[Parent(i)]>h.A[i])
		{
			cout<<"Error: Min-Heap property violated"<<endl;
			 return 1;
		}
 
	cout<<"Calling Heapsort\n";
	h.Heapsort();
	cout<<"Sorted output (in descending order)\n";
	for(i=0;i<n;i++) cout<<"A["<<i<<"]="<<h.A[i]<<endl;

	return 0;
}
