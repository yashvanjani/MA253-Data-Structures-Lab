#include "perfect.h"
#include <cstdlib>
int max(int h[],int n)
{
	int maxrep=0;
	int temp=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		int a=h[i];
		temp=0;
		for(j=0;j<n;j++)
		{
			if(h[i]==h[j])
				temp++;
		}
		if(temp>maxrep)
			maxrep=temp;
	}
	return maxrep;
}
// write your code here
hparam f1(int p,int m,int n ,int *A)
{
	int a=0,b=0;
	int i;
	int h[n];
	for(i=0;i<n;i++)
	{
		h[i]=((a*A[i]+b) % p) % m;
	}

	while(max(h,n)>5)
	{
		a=rand()%p;
		b=rand()%p;
		for(i=0;i<n;i++)
		{
			h[i]=((a*A[i]+b) % p) % m;
		}
	}
	hparam final;
	final.a=a;
	final.b=b;
	return final;
}

hparam f2(int p,int m,int n,int *A)
{
	int a=0,b=0;
	int i;
	int h[n];
	for(i=0;i<n;i++)
	{
		h[i]=((a*A[i]+b) % p) % m;
	}

	while(max(h,n)>1)
	{
		a=rand()%p;
		b=rand()%p;
		for(i=0;i<n;i++)
		{
			h[i]=((a*A[i]+b) % p) % m;
		}
	}
	hparam final;
	final.a=a;
	final.b=b;
	return final;
}