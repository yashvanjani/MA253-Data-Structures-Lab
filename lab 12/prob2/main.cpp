#include <iostream>
#include <algorithm>
#include "toposort.h"
using namespace std;

int main(int argc, char *argv[])
{
	int n,m,u,v;
	cout<<"Enter no. of vertices"<<endl;
	cin>>n;
	cout<<"Enter no. of edges"<<endl;
	cin>>m;
	int (*E)[2] = new int[m][2];
	cout<<"Enter "<<m<<" pairs of integers u v to add edge (u,v)"<<endl;
	for(int i=0;i<m;i++) cin>>E[i][0]>>E[i][1];
	int *A = new int[n];
	toposort(n,m,E,A);
	if(argc>1) {for(u=0;u<n;u++) cout<<A[u]<<" "; cout<<endl;}
	int *B = new int[n]; 
	for(u=0;u<n;u++) B[u]=A[u]; sort(B,B+n);
	for(u=0;u<n;u++) if(B[u]!=u)
	{cout<<"Error: Array A does not contain vertex "<<u<<endl; return 1;}
	for (int e=0;e<m;e++)
	{
		bool f=false;
		for(u=0;A[u]!=E[e][0];u++);
		for(v=u+1;v<n;v++) if(A[v]==E[e][1]) {f=true; break;}
		if(!f)
		{
			cout<<"Dependance faild for edge ("<<E[e][0]<<","<<E[e][1]<<")"<<endl;
			return 2;
		}
	}
	cout<<"Ok"<<endl;
}
