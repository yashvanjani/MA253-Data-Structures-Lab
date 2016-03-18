//Include header for string handling
#include <string>
#include "sortrecord.h"
using namespace std;

//Define the 'sort' function that you declared in 'sortrecord.h' header.
//Use insertion sort algorithm.

// write your code here
void sort(student A[], int n)
{
	int i,j;
	student key;
	for(j=1;j<n;j++)
	{
		key.id=A[j].id;
		key.roll=A[j].roll;
		i=j-1;
		while((i>=0)&&(A[i].id>key.id))
		{
			A[i+1].id=A[i].id;
			A[i+1].roll=A[i].roll;
			i--;
		}
		A[i+1].id=key.id;
		A[i+1].roll=key.roll;
	}
}