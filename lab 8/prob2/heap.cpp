#include "heap.h"
#include <limits.h>
int x = INT_MAX;

heap::heap(int s)
{
	A = new int[s]; heap_size=0; length=s;
}

//Implement the following functions
//
//int Parent(int)
//int Child(int,int)
//void heap::MinHeapify(int)
//int heap::HeapExtractMin(void)
//void heap::HeapDecreaseKey(int, int)
//void heap::MinHeapInsert(int)

// write your code here

int Parent(int i)
{
	return int(i-1)/3;
}

int Child(int i,int j)
{
	return ((3*i)+j);
}

void heap::MinHeapify(int i)
{
	int left=3*i+1;
	int mid=3*i+2;
	int right=3*i+3;
	int smallest;

	if(left < heap_size && A[left]<A[i])
		smallest=left;
	else 
		smallest=i;
	if(mid<heap_size && A[mid]<A[smallest])
		smallest=mid;
	if(right<heap_size && A[right]<A[smallest])
		smallest=right;
	if(smallest!=i)
	{
		A[i]=A[i]+A[smallest];
		A[smallest]=A[i]-A[smallest];
		A[i]=A[i]-A[smallest];
		MinHeapify(smallest);
	}

}

void heap::BuildMinHeap(void)
{
	heap_size=length;
	for(int j=int(length-1)/2;j>=0;j--)
		MinHeapify(j);
}

int heap::HeapExtractMin(void)
{
	int min = A[0];
	A[0]=A[heap_size-1];
	heap_size--;
	MinHeapify(0);
	return min;
}

void heap::HeapDecreaseKey(int i, int k)
{
	A[i]=k;
	while(i>0 && A[Parent(i)]>A[i])
	{
		A[i]=A[i]+A[Parent(i)];
		A[Parent(i)]=A[i]-A[Parent(i)];
		A[i]=A[i]-A[Parent(i)];
		i=Parent(i);
	}
}

void heap::MinHeapInsert(int k)
{
	heap_size++;
	//A[heap_size-1]=x;
	HeapDecreaseKey((heap_size-1),k);
}
