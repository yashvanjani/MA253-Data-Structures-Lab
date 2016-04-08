#include "lis.h"
#include <cstdlib>
#include <iostream>
using namespace std;
//Implement lis(). See 'lis.h' for declaration of lis()
// write your code here
void PRINT_LCS(int **b,int *X,int i,int j,int *B, int m)
{
	
	if((i==0) || (j==0))
	{
		return;
	}
	if(b[i-1][j-1]==1)
	{

		PRINT_LCS(b,X,i-1,j-1,B,(m-1));
		B[m-1]=i-1;
	}
	else 
	{
		if(b[i-1][j-1]==2)
		{
			PRINT_LCS(b,X,i-1,j,B,m);
		}
		else
		{
			PRINT_LCS(b,X,i,j-1,B,m);
		}
	}
	for(i=0;i<m;i++)
	{
		B[i]=i;
	}
}
void lis(int n,int *A, int &m , int* &B)
{
	int temp[n];
	int i,j,k;
	int k_largest=0;
	int *C;
	C=new int[n];
	for(i=0;i<n;i++)
	{
		C[i]=A[i];
	}
	int min;
	for(i=0;i<n-1;i++)
	{
		min=i+1;
		for(j=i+1;j<n;j++)
		{
			if(C[j]<C[min])
			{
				min=j;
			}
		}
		if(C[min]<C[i])
		{
			C[min]=C[min]+C[i];
			C[i]=C[min]-C[i];
			C[min]=C[min]-C[i];
		}
	}
	int **b;
	b=new int*[n];
	for(i=0;i<n;i++)
		b[i]=(int *)malloc(sizeof(int));
	int c[n+1][n+1];
	for(i=1;i<n+1;i++)
	{
		c[i][0]=0;
	}
	for(i=0;i<n+1;i++)
	{
		c[0][i]=0;
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(A[i-1]==C[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i-1][j-1]=1; //d=1
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i-1][j-1]=2; //u=2
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i-1][j-1]=3; //l=3
			}
		}
	}
	m=c[n][n];
	B=new int[m];
	
	PRINT_LCS(b,A,n,n,B,m);
	
	// for(i=0;i<m;i++)
	// {
	// 	cout<<B[i];
	// }
}

