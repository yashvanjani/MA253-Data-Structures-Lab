#include "node.h"
class bst
{
	public:
	node *root;

	bst(void);
	void Populate(int);
	void Show(void);
	
	void InorderTreeWalk(node *);
	node *TreeSearch(node *, int);
	node *IterativeTreeSearch(node *, int);
	node *TreeMinimum(node *);
	node *TreeMaximum(node *);
	node *TreeSuccessor(node *);
	node *TreePredecessor(node *);
	
	void TreeInsert(node *);
	void Transplant(node *, node *);
	void TreeDelete(node *);
};
