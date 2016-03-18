#include <iostream>
#include <cstdlib>
#include "heap.h"
using namespace std;

bool check(heap &,int);
bool check(heap &h, int n)
{
	int i;
	for(i=1;i<n;i++)
		if(h.A[Parent(i)]>h.A[i])
		{
			cout<<"Error: Min-Heap property violated"<<endl;
			return false;
		}
	return true;

}

int main()
{
	int n,i,x;

	cout<<"Testing MinHeapInsert()\n";
	cout<<"How many integers do you want to enter ?"<<endl;
	cin>>n;
	heap h(n);
	cout<<"Enter "<<n<<" integers"<<endl;

	for(i=0;i<n;i++)
	{
		cout<<"key#"<<i<<": ";cin>>x;
		cout<<"Inserting "<<x<<endl;
		h.MinHeapInsert(x);
		if(!check(h,i+1))
		{cout<<"MinHeapInsert failed\n";return 1;}
	}

	cout<<"Testing HeapDecreaseKey()\n";
	for(int j=0;j<10;j++) 
	{
		i = rand()%n;
		h.HeapDecreaseKey(i,h.A[i]-1);
		if(!check(h,n))
		{cout<<"HeapDecreaseKey failed\n";return 1;}
	}

	cout<<"Testing HeapExtractMin()\n";
	for(i=n;i>0;i--)
	{
		cout<<h.HeapExtractMin()<<" extracted\n";
		if(!check(h,i-1))
		{cout<<"HeapExtractMin failed\n";return 1;}
	}

	return 0;
}
