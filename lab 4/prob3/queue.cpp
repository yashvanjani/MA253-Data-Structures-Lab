#include "queue.h"

//You need to define the member functions of class 'queue'
//  which are not inherited from class 'list'
//Define the member functions enqueue() and dequeue()

// write your code here
void queue::enqueue(int a)
{
	push_back(a);
}

int queue::dequeue(void)
{
	pop_front();
}