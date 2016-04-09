#include "bitonic.h"
#include <iostream>
#include <vector>

using namespace std;

//Implement function 'bitonic()'. It is declared in 'bitonic.h'
// write your code here
void print_path(point p[], vector< vector<int> > &r, int i, int j)
{
	if(i<j)
	{
		int k=r[i][j];
		cout<<p[k].x;
		if(k>0)
			print_path(p,r,i,k);
	}
	else
	{
		int k=r[j][i];
		if(k>0)
		{
			print_path(p,r,k,j);
			cout<<p[k].x;
		}
	}
}
void print_tour(point p[],vector< vector<int> > &r,int n)
{
	cout<<p[n-1].x;
	cout<<p[n-2].x;
	int k=r[n-2][n-1];
	print_path(p,r,k,n-2);
	cout<<p[k].x;
}


void bitonic(int n,point p[],bool T[])
{
	
	int i,j,k,q;
	int min;
	
	
	//starting euclidean-tsp

	vector< vector<int> > b(n, vector<int>(n) );
	vector< vector<int> > r(n, vector<int>(n) );
	b[0][1]=d(p[0],p[1]);
	for(j=2;j<n;j++)
	{
		for(i=0;i<=j-2;i++)
		{
			b[i][j]=b[i][j-1]+d(p[j-1],p[j]);
			r[i][j]=j-1;
		}
		b[j-1][j]=10000;
		for(k=0;k<j-2;k++)
		{
			q=b[k][j-1]+d(p[k],p[j]);
			if(q<b[j-1][j])
			{
				b[j-1][j]=q;
				r[j-1][j]=k;
			}
		}
	}
	b[n-1][n-1]=b[n-2][n-1]+d(p[n-2],p[n-1]);
	print_tour(p_sorted,r,n);
}
