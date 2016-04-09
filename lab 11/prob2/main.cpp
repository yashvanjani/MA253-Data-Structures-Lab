#include <iostream>
#include "pal.h"
using namespace std;

int main(int argc, char *argv[])
{
	int n,i,j; char *A;
	cout<<"Enter length of sequence\n";
	cin>>n; A = new char[n];
	cout<<"Enter "<<n<<" characters\n";
	for(i=0;i<n;i++) cin>>A[i];

	int m, *B;
	pal(n,A,m,B);

	if(argc>1) 
	{
		cout<<"m = "<<m<<endl;
		for(i=0,j=0;i<n;i++)
		{
			cout<<"A["<<i<<"]="<<A[i];
			if(i==B[j]) {cout<<"\tB["<<j<<"]="<<i;j++;}
			cout<<endl;
		}
	}
	// for(i=0;i<m;i++)
	// 	cout<<A[B[i]];

	for(i=0;i<m-1;i++)
	{
		if(B[i+1]<=B[i]) {cout<<"Error: B[i+1]<=B[i] for i="<<i;return 1;}
		if(A[B[i]]!=A[B[m-1-i]]) {cout<<"Error: A["<<B[i]<<"]!=A["<<B[m-1-i]<<"]";return 2;}
	}
	if(argc>1)
	{
		cout<<"Original sequence: ";for(i=0;i<n;i++) cout<<A[i]; cout<<endl;
		cout<<"Largest Palindromic Subseq: ";for(i=0;i<m;i++) cout<<A[B[i]]; cout<<endl;
	}
	// for(i=0;i<m;i++)
	// 	cout<<A[B[i]];
	cout<<"Length of Largest Palindromic Subsequence is "<<m<<endl;
}
