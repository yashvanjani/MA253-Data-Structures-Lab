#ifndef NODE_H
#define NODE_H 1
struct node
{
	int key;
	float sat;
	node *left, *right, *p;
};
#endif
