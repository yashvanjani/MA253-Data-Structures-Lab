#include <iostream>
#include "dia.h"
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
	cout<<"Diameter of graph: "<<dia(n,m,E)<<endl;
}
