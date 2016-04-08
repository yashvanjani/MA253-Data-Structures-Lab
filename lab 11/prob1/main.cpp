#include <iostream>
#include "lis.h"
using namespace std;

int main(int argc, char *argv[])
{
	int n, *A, i,j;
	cout<<"Enter length of sequence\n";
	cin>>n; A = new int[n];
	cout<<"Enter "<<n<<" integers\n";
	for(i=0;i<n;i++) cin>>A[i];

	int m, *B;
	lis(n,A,m,B);

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

	for(i=1;i<m;i++)
	{
		if(B[i]<=B[i-1]) {cout<<"Error: B[i]<=B[i-1] for i="<<i<<"B["<<i<<"]="<<B[i]<<",B["<<(i-1)<<"]="<<B[i-1];return 1;}
		if(B[i]<B[i-1]) {cout<<"Error: B[i]<B[i-1] for i="<<i;return 2;}
	}
	cout<<"Length of LIS is "<<m<<endl;
}
