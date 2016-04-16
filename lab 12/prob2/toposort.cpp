#include "toposort.h"
#include <iostream>
#include <vector>

using namespace std;
//Implement toposort()
// write your code here
void indegree_update(int n, int m, vector< vector<int> > &graph, int indegree[])
{
	int i,j;
	for(j=0;j<n;j++)
	{
		indegree[j]=0;
		for(i=0;i<n;i++)
		{
			if(graph[i][j]==1)
				indegree[j]++;
		}
		//cout<<indegree[j];
	}
}
void graph_update(int n, int m, vector< vector<int> > &graph, int vertex_to_remove)
{
	int i;
	for(i=0;i<n;i++)
	{
		graph[vertex_to_remove][i]=0;
		graph[i][vertex_to_remove]=0;
	}

}
void toposort(int n, int m, int E[][2], int A[])
{
	//int graph[n][n];
	vector< vector<int> > graph(n, vector<int>(n) );
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			graph[i][j]=0;
		}
	}
	
	for(i=0;i<m;i++)
	{
		graph[E[i][0]][E[i][1]]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//cout<<graph[i][j]<<" ";
		}
		//cout<<"\n";
	}
	int indegree[n];
	indegree_update(n,m,graph,indegree);
	int k=0;
	int count=0;
	for(i=0;i<n;i++)
		A[i]=-1;
	while(k<n)
	{
		for(i=0;i<n;i++)
		{
			if(indegree[i]==0)
			{
				count=0;
				for(j=0;j<n;j++)
				{
					if(i==A[j])
					{
						count++;
					}
				}
				if(count==0)
					break;
			}
		}
		//now i contains value of vertex whose indegree is zero
		A[k]=i;
		k++;
		graph_update(n,m,graph,i);
		indegree_update(n,m,graph,indegree);
	}

}
