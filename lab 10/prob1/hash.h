#define NIL -1
#define DELETED -2

class hash
{
	public:
	int *T, m;

	hash(int);
	int h(int,int);
	int HashSearch(int);
	int HashInsert(int);
	int HashDelete(int);
};
