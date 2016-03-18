#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

int main()
{
	queue q(3);
	string c="";
	int v;

	cout<<"Demonstration of QUEUE using ARRAY"<<endl;
	cout<<"Enter one the follwing commands"<<endl;
	cout<<" i - to enqueue an integer"<<endl;
	cout<<" d - to dequeue"<<endl;
	cout<<" p - to print the queue"<<endl;
	cout<<" q - to quit"<<endl;

	while(true)
	{
		cout<<"\nEnter command"<<endl; cin>>c;
		if(c=="q") break;
		if(c=="i")
		{
			if(q.isfull()) {cout<<"Error: Overflow"<<endl; continue;}
			cout<<"Enter value"<<endl; cin>>v;
			q.enqueue(v); cout<<v<<" Enqueued"<<endl;
			continue;
		}
		if(c=="d")
		{
			if(q.isempty()) {cout<<"Error: Underflow"<<endl; continue;}
			cout<<q.dequeue()<<" Dequeued"<<endl;
			continue;
		}
		if(c=="p") {q.show();continue;}
		cout<<"Command not recognised"<<endl;
	}
}
