#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
	stack s(3);
	string c="";
	int v;

	cout<<"Demonstration of STACK using ARRAY"<<endl;
	cout<<"Enter one the follwing commands"<<endl;
	cout<<" i - to push an integer"<<endl;
	cout<<" d - to pop"<<endl;
	cout<<" p - to print the stack"<<endl;
	cout<<" q - to quit"<<endl;

	while(true)
	{
		cout<<"\nEnter command"<<endl; cin>>c;
		if(c=="q") break;
		if(c=="i")
		{
			if(s.isfull()) {cout<<"Error: Overflow"<<endl; continue;}
			cout<<"Enter value"<<endl; cin>>v;
			s.push(v); cout<<v<<" Pushed"<<endl;
			continue;
		}
		if(c=="d")
		{
			if(s.isempty()) {cout<<"Error: Underflow"<<endl; continue;}
			cout<<s.pop()<<" Popped"<<endl;
			continue;
		}
		if(c=="p") {s.show();continue;}
		cout<<"Command not recognised"<<endl;
	}
}
