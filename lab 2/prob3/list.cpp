#include <iostream>
using namespace std;

struct node {int data; node *next;};

int main()
{
	int x;
	node *h=NULL, *temp=NULL;

	while(true)
	{
		cout<<"Enter a +ve integer (enter non +ve to stop)"<<endl;
		cin>>x;
		if(x<=0) break;

		//Write code for inserting 'x' at the end of the list
		//Use 'temp' as a temopary variable, which stores the address of the last node.
		//Code for displaying and deallocating the list should give you some idea.
		if(h==NULL) //If the list is empty we need to modify 'h'
		{
			//Allocate space to store one node element;
			//The head 'h' must point to the address of the allocated memory
			// and 'temp' should point to that address too
// write your code here
			h = new node;
			temp = h;
		}
		else //If the list is not empty we do not need to modify 'h'
		{
			//Allocate space to store one node element;
			//'next' element of the last node must point to the address of the allocated memory
			//  in this way the new block becomes the last node.
			//Modify 'temp' so that it points to this new last node.
// write your code here
			temp->next=new node;
			temp=temp->next;
		}
		//Set the 'data' field of the newly created node as 'x'
		//Set the 'next' field as NULL
// write your code here
		temp->data=x;
		temp->next=NULL;
	} 

	//Code for displaying the list
	for(temp=h;temp!=NULL;temp=temp->next) cout<<"-> "<<temp->data<<" ";
	cout<<endl;
	
	//Deallocating
	while(h!=NULL) {temp=h; h=h->next; delete temp;}

	return 0;
}
