#include <iostream>
//Include header for string handling
#include <string>
#include "sortrecord.h"

using namespace std;

int main()
{
	int n;
	cout<<"Enter the number of students"<<endl;
	cin>>n;
	//Define an arry of 'student' datatype using dynamic allocation
	//Name of array should be 'A' and length of the array should be 'n'
	student *A;
	A=new student[n];


// write your code here

	for(int i=0;i<n;i++)
	{
		cout<<"Enter roll for student# "<<i+1<<endl;
		cin>>A[i].roll;
		cout<<"Enter id for student# "<<i+1<<endl;
		cin>>A[i].id;
	}

	sort(A,n);

	for(int i=0;i<n;i++) 
		cout<<A[i].id<<" "<<A[i].roll<<endl;

	//Deallocate the array 'A'
	delete[] A;

// write your code here

	return 0;
}

