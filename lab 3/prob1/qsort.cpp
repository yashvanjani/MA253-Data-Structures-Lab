#include "qsort.h"
using namespace std;

//Define the functions 'quicksort' and 'partition'
//These functions are declared in 'qsort.h' header.
//Read the 'qsort.h' file (but do not modify it) to know what should be the
// return-type, argument-type and number of arguments of these functions
// Define the functions accordingly.

// write your code here
void quicksort(int A[], int a, int b)
{
	int t;
	if (a<b)
	{
		t=partition(A,a,b);
		quicksort(A,a,t-1);
		quicksort(A,t+1,b);
	}

}

int partition(int *A, int a, int b)
{
	int temp,i=a,j,pivot=A[a];
	for(j=a+1;j<=b;j++)
	{
		if(A[j]<=pivot)
		{
			i=i+1;
			temp=A[j];
			A[j]=A[i];
			A[i]=temp;
		}
	}
	temp=A[i];
	A[i]=A[a];
	A[a]=temp;
	return i;
}