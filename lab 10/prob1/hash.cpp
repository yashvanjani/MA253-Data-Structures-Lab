#include "hash.h"

hash::hash(int size)
{
	m = size;
	T = new int[m];
	for(int i=0;i<m;i++) T[i]=NIL;
}

//Implement HashSearch(), HashInsert(), HashDelete() for open addressing
//Implement hash function h() which uses linear probing with
// auxiliary hash function h'(k)=k

// write your code here
int hash::h(int k,int i)
{
	int h=(k+i)%m;
	return h;
}

int hash::HashSearch(int k)
{
	int i,j;
	for(i=0, j=h(k,i) ;(i<=m)||(T[j]==NIL); ++i, j=h(k,i))
	{
		if(T[j]==k)
		{
			return j;
			break;
		}
	}
	return NIL;

}

int hash::HashInsert(int k)
{
	
	int i,j;
	for(i=0, j=h(k,i) ;(i<=m)||(T[j]==NIL); ++i, j=h(k,i))
	{
		if(T[j]==NIL || T[j]==DELETED)
		{
			T[j]=k;
			return j;
			break;
		}
	}
	return NIL;
}

int hash::HashDelete(int k)
{
	int j=HashSearch(k);
	if(T[j]!=NIL && T[j]!=DELETED)
	{
		T[j]=DELETED;
		return j;
	}
	else
		return NIL;
}
