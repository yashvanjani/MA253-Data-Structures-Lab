#include "dia.h"
#include <iostream>
using namespace std;
#include <list>
#include <queue>
//Implement function dia()
// write your code here
struct vertex
{
	int col;
	int dist;
	int pi;
};
int dia(int a, int b, int E[][2])
{
	int n,m;
	int i,j;
	n=a;
	m=b;
	int matrix[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			matrix[i][j]=0;
		}
	}
	for(i=0;i<m;i++)
	{	
		matrix[E[i][0]][E[i][1]]=1;
		matrix[E[i][1]][E[i][0]]=1;
	}
	vertex v[n];
	int max=0,k=0;
	int dl[n];
	for(i=0;i<n;i++) 
	{	
		dl[i]=0;
	}	
	queue <int> Queue;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(i==j)
				continue;
			else 
			{
				v[i].col=0;
				v[i].dist=0;
				v[i].pi=-100;
			}
		}
		v[j].col=1;
		v[j].dist=0;
		v[j].pi=-100;
		while(!Queue.empty())
		{
			Queue.pop();
		}
		Queue.push(j);
		while(!Queue.empty())
		{
			k=Queue.front();
			Queue.pop();
			for(i=0;i<n;i++)
			{
				if(matrix[k][i]==1)
					{
						
						if(v[i].col==0)
						{
							v[i].col=1;
							v[i].dist=v[k].dist+1;
							v[i].pi=k;
							Queue.push(i);
						}
						if(v[i].dist>=dl[j])
							dl[j]= v[i].dist;
					}
  				
			}
			v[k].col=2;/* col =2 means the vertex has been explored*/
		}
		if(dl[j]>max)
			max=dl[j];
	}
	return max;
}