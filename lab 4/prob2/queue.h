class queue 
{
	public:
	void enqueue(int);
	int dequeue(void);
	bool isempty(void);
	bool isfull(void);
	void show(void);

	queue(int);
	~queue(void);

	private:
	int MAX, *q, start, end;
};
