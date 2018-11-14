class Stack
{
	int sp;
	int s[256];
public:
	Stack();

	virtual void push(int i);
	virtual int pop();
	virtual bool empty();
	virtual bool full();
};
