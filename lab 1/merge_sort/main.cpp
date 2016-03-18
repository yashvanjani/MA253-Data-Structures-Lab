#include <iostream>

using namespace std;
void merge_sort(int [],int,int);
void merge(int[],int,int,int);
int main()
{
	int n;
	cout<<"Number of input: ";
	cin>>n;
	cout<<"\n";
	int input[n];
	int i;
	for (i=0;i<n;i++)
	{
		cout<<"#"<<i<<":";
		cin>>input[i];
		//cout<<"\n";
	}
	
	
	merge_sort(input,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<input[i]<<"\n";
	}

}

void merge_sort(int a[], int p, int r)
{
	int q;
	if (p<r)
	{	
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);			
	}
}

void merge(int b[], int p, int q, int r)
{
	int n1,n2,i,j,k;
	n1=q-p+1;
	n2=r-q;
	int L[1000];
	int R[1000];
	for(i=0;i<n1;i++)
	{
		L[i]=b[p+i];
	}
	for (j=0;j<n2;j++)
	{
		R[j]=b[q+j+1];
	}
	i=0;j=0;
	for(k=p;k<r+1;k++)
	{
		if(i<n1 && j<n2)		
		{
			if(L[i]<=R[j])
			{
				b[k]=L[i];
				i++;
			}
			else
			{
				b[k]=R[j];
				j++;
			}
		}
//new code by souymitra
		else if(i<n1)
		{
			b[k]=L[i];
			i++;
		}
		else if(j<n2)
		{
			b[k]=R[j];
			j++;
		}
	}
}

