class stack
{
	public:
	void push(int);
	int pop(void);
	bool isempty(void);
	bool isfull(void);
	void show(void);

	stack(int);
	~stack(void);

	private:
	int MAX, *s, top;
};
