int Parent(int);
int Child(int,int);

class heap
{
	public:
	int *A, heap_size, length;

	heap(int);
	void MinHeapify(int);
	void BuildMinHeap(void);
	void Heapsort(void);
	int HeapMinimum(void);
	int HeapExtractMin(void);
	void HeapDecreaseKey(int,int);
	void MinHeapInsert(int);
};
