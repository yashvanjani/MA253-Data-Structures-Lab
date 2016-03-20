void rbtree::LeftRotate(node *x)
	{
		node *y= x->right;
		x->right = y->left;
		if(y->left != nil) y->left->p = x;
		y->p = x->p;
		if(x->p == nil) root =y;
		else 	{
				if(x == x->p->left) x->p->left = y;
				else x->p->right = y;			
			}
		y->left = x;
		x->p = y;
	}

void rbtree::RightRotate(node *x)
	{
		node *y= x->left;
		x->left = y->right;
		if(y->right != nil) y->right->p = x;
		y->p = x->p;
		if(x->p == nil) root =y;
		else 	{
				if(x == x->p->left) x->p->left = y;
				else x->p->right = y;			
			}
		y->right = x;
		x->p = y;
	}

void rbtree::RBInsert(node *x)
	{
		node *y=nil;
		node *z=root;
		while(z!=nil)
			{
				y=z;
				if(x->key < z->key) z=z->left;
				else z=z->right;				
			}
		x->p=y;
		if(y==nil) root =x;
		else	{
				if(x->key < y->key) y->left = x;
				else y->right = x;
			}
		x->left=nil;
		x->right=nil;
		x->color=RED;
		RBInsertFixup(x);
	}

void rbtree::RBInsertFixup(node *z)
	{	node *y;
		while(z->p->color ==RED)
			{
				if(z->p == z->p->p->left) 
					{	y= z->p->p->right;
						if(y->color ==RED)
						{
							z->p->color = BLACK;
							y->color = BLACK;
							z->p->p->color = RED;
							z=z->p->p;
						}
						else    { if(z==z->p->right) {z=z->p; LeftRotate(z);}
							z->p->color = BLACK;
							z->p->p->color = RED;
							RightRotate(z->p->p);	
							}
					}
				
				else 	{
						y=z->p->p->left;
						if(y->color ==RED)
						{
							z->p->color = BLACK;
							y->color = BLACK;
							z->p->p->color = RED;
							z=z->p->p;
						}
						else    { if(z==z->p->left) {z=z->p; RightRotate(z);}
							z->p->color = BLACK;
							z->p->p->color = RED;
							LeftRotate(z->p->p);	
							}
					}			
			}
		root->color = BLACK;
	}