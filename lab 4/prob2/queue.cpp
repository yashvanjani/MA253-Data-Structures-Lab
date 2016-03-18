#include "queue.h"

//Define all the member functions (except show()) of class 'queue'
// which are declared in header file 'queue.h'

// write your code here
queue::queue(int size)
{
	MAX=size;
	q = new int[MAX];
	start=-1;
	end=-1;
}

queue::~queue(void)
{
	delete[] q;
}

void queue::enqueue(int a)
{
	if(isempty()==true)
	{
		start=0;
		end=0;
		q[end]=a;
	}
	else
	{
	q[end]=a;
	end=(end+1)%MAX;
	}	
}

int queue::dequeue(void)
{
	if(start==end)
	{
		int t =q[start];
		start=-1;
		end=-1;
		return t;

	}
	start=(start+1)%MAX;
	return q[start];
	
	
	
}

bool queue::isempty(void)
{
	if(start==-1 && end==-1)
		return true;		
	else
		return false;
}

bool queue::isfull(void)
{
	if(start==(end+1)%MAX)
		return true;
	else
		return false;
}

/*queue::queue(int size)
{
	MAX=size;
	q = new int[MAX];
	start=0;
	end=-1;
}

queue::~queue(void)
{
	delete[] q;
}

void queue::enqueue(int a)
{
	end=(end+1)%MAX;
	q[end]=a;	
}

int queue::dequeue(void)
{
	int t =q[start];
	start=(start+1)%MAX;
	if(isempty()==true)
	{
		start=0;
		end=-1;
	}
	
	return t;
}

bool queue::isempty(void)
{
	if((start==((end+1)%MAX) && (q[end-1]!=))|| end==-1)
	{
		return true;
		start=0;
		end=-1;
	}
		
	else
		return false;
}

bool queue::isfull(void)
{
	if(end!=-1 && start==(end+1)%MAX)
		return true;
	else
		return false;
}*/