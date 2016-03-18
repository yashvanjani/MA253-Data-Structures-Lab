#include <iostream>
using namespace std;

//Write declaration of swap function
int swap(int &, int &);
// write your code here

int main()
{
	int x,y;
	cout << "Enter an integer "<<endl;
	cin>>x;
	cout << "Enter another integer "<<endl;
	cin>>y;
	swap(x,y);
	cout<<"Swapped values "<<x<<" "<<y<<endl;
	return 0;
}

//Write definition of swap function
int swap (int &a, int &b)
// write your code here
{
	a=a+b;
	b=a-b;
	a=a-b;
}