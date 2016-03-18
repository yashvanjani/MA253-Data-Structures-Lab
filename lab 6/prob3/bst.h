#ifndef BST_H
#define BST_H 1
#include "node.h"
class bst
{
	public:
	node *root;

	bst(void);

	int Size(node *);
	int Height(node *);
	
	void InorderTreeWalk(node *);
	void TreeInsert(node *);
};
#endif
