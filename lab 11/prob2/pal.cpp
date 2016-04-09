#include "pal.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//Implement pal(). See pal.h for declaration of pal()
// write your code here

void get_lcs(int i,int j,char *A,int m, int *&B, vector< vector<int> > &b)
{
	if( (i==0) || (j==0) ){
		return;
	}
	if (b[i-1][j-1] == 0) {
		B[m-1] = i-1;
		get_lcs(i-1,j-1,A,m-1,B,b);
		
	} else if (b[i-1][j-1] == -1) {
		get_lcs(i,j-1,A,m,B,b);
	} else {
		get_lcs(i-1,j,A,m,B,b);
	}

	
	
	// if(b[i-1][j-1]==0)
	// {
	// 	get_lcs(i-1,j-1,A,m-1,B,b);
	// 	B[m-1]=i-1;
		
	// }
	// else if(b[i][j]==1)
	// {
	// 	get_lcs(i-1,j,A,m,B,b);
	// }
	// else
	// {
	// 	get_lcs(i,j-1,A,m,B,b);
	// }

	
}

void pal(int n ,char *A, int &m, int *&B)
{
	char *C;
	int i,j;
	C = new char[n];
	for(i=0; i<n;i++)
		C[i]=A[n-i-1];
	// cout<<"A=";
	// for(i=0;i<n;i++)
	// 	cout<<A[i];
	// cout<<"\nC=";
	// for(i=0;i<n;i++)
	// 	cout<<C[i];
	// cout<<"\n";
	//cout<<"C matrix formed\n";

	int c[n+1][n+1];
	vector< vector<int> > b(n, vector<int>(n) );
	//cout<<"space allocation for b & c done\n";
	//building b & c matrix
	for(i=0;i<=n;i++)
		c[i][0]=0;
	for(i=1;i<=n;i++)
		c[0][i]=0;
	//cout<<"c[0][i] and c[i][0] allocated\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(A[i-1]==C[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i-1][j-1]=0; //diagonal=0
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i-1][j-1]=1; //up=1
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i-1][j-1]=(-1); //left=(-1)
				}
			}
		}
	}
	//cout<<"b & c formed\n";
	m=c[n][n];
	B=new int[m];
	//cout<<"m ="<<m<<"\n";
	get_lcs(n,n,A,m,B,b);

}
