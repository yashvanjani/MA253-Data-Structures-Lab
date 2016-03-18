//You need to include 'list.h'
// if you want to use 'list' as base class

// write your code here

//Now define a class 'queue'
//'queue' should be derived from base class 'list'
//The inheritance should be a public inheritance
//Class 'queue' must have two new public  member functions enqueue() and dequeue()

// write your code here
#include "list.h"

class queue : public list
{
	public:
		void enqueue(int);
		int dequeue(void);

	private:
		int MAX, *q, start, end;
};
