#include <iostream>
#include <iomanip>
#include "rbtree.h"
#include "other.h"
using namespace std;
int mys[50], top;

void fd(node *, int, node *);

char outr=0x6a, outl=0x6b, outb=0x75, inr=0x6c, inl=0x6d, vbar=0x78;

void sn(node *x)
{
	cout<<x->key<<":";
	if(x->color==RED) cout<<"R";
	else if (x->color==BLACK) cout<<"B";
	else cout<<"N";
}

void rbtree::show(node *x)
{
	if(x==nil) return;
	sn(x);
	cout<<",\tLeft ";if(x->left==nil) cout<<"nil"; else sn(x->left);
	cout<<",\tRight ";if(x->right==nil) cout<<"nil"; else sn(x->right);
	cout<<",\tParent ";if(x->p==nil) cout<<"nil"; else sn(x->p);
	cout<<endl;
	show(x->left);
	show(x->right);
}

void draw(rbtree& t) {top=-1;fd(t.root,0,t.nil);}

void fd(node *x, int l, node *nil)
{
	char c;
	if(x==nil) return;
	if(x==x->p->left) mys[++top]=l;
	fd(x->right,l+1,nil);
	if(x==x->p->left) top--;
	int j=0;
	for(int i=0;i<=top;i++)
	{
		for(;j<mys[i];j++) cout<<"    ";
		cout<<char(27)<<"(0"<<vbar<<char(27)<<"(B   ";
		j++;
	}
	for(;j<l;j++) cout<<"    ";
	if(l==0) c=' '; else if(x==x->p->left) c=inl; else c=inr;
	cout<<char(27)<<"(0"<<c<<char(27)<<"(B";
	if(x->color==RED) cout<<char(27)<<"[41m";
	if(x->color==BLACK) cout<<char(27)<<"[40m";
	cout<<setw(3)<<x->key;
	cout<<char(27)<<"[m";
	if(x->left==nil && x->right==nil) c=' ';
	if(x->left==nil && x->right!=nil) c=outr;
	if(x->left!=nil && x->right==nil) c=outl;
	if(x->left!=nil && x->right!=nil) c=outb;
	cout<<char(27)<<"(0"<<c<<char(27)<<"(B"<<endl;
	if(x==x->p->right) mys[++top]=l;
	fd(x->left,l+1,nil);
	if(x==x->p->right) top--;
}
