#include <iostream>

using namespace std;
void ins_sort(int [], int);
int main()
{

	int x[5];
	int i;
	for(i=0;i<5;i++)
	{
		cin>>x[i];	
	}
	ins_sort(x,5);
	for (i=0;i<5;i++)
		cout<<x[i]<< "\n";

}

void ins_sort(int x[],int n)
{

	int key,i;
	int k;

	for (i=1;i<5;i++)
	{
		key=x[i];
		int j;
		for (j=i-1;j>=0;j--)
		{
			if(key<x[j])
			{	
				for(k=i;k>0;k--)
				{
					x[k]=x[k-1];
				}
				x[j]=key;
			}
		}
	
	}
	

}
