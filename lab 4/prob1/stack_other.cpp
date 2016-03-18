#include <iostream>
#include "stack.h"
using namespace std;

void stack::show(void)
{
	for(int i=0;i<=top;i++) cout << s[i] << " ";
	cout << endl;
}
