#include <iostream>
#include "queue.h"
using namespace std;

void queue::show(void)
{
	for(int i=start;i<=end;i++) cout << q[i] << " ";
	cout << endl;
}
