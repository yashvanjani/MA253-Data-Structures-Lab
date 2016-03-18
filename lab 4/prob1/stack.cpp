#include "stack.h"

//Define all the member functions (except show()) of class 'stack'
// which are declared in header file 'stack.h'

// write your code here

stack::stack(int size)
{
	MAX = size;
	s = new int[MAX];
	top=-1;
}

stack::~stack(void)
{
	delete[] s;
}

void stack::push(int a)
{
	top++;
	s[top]=a;
}

int stack::pop(void)
{
	int t =s[top];
	top--;
	return t;
}

bool stack::isempty(void)
{
	if(top==-1)
		return true;
	else
		return false;
}

bool stack::isfull(void)
{
	if(top==MAX-1)
		return true;
	else
		return false;
}