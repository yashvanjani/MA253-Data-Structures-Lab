#ifndef RBTREE_H
#define RBTREE_H 1
enum rbcol {NONE,RED,BLACK};

struct node
{
	int key;
	node *left,*right,*p;
	rbcol color;
};

class rbtree
{
	public:
	node* nil;
	node *root;
	rbtree(void);
	void show(node*);
	void LeftRotate(node*);
	void RightRotate(node*);
	void RBInsert(node*);
	void RBInsertFixup(node*);
	void RBTransplant(node *, node *);
	void RBDelete(node *);
	void RBDeleteFixup(node *);

	node *TreeMinimum(node*);
	node *TreeSearch(node*,int);
};
#endif
