#ifndef STACK_H
#define STACK_H

class Stack
{
	int sp;
	int s[256];
public:
	Stack();
	virtual ~Stack();

	virtual void push(int i);
	virtual int pop();
	virtual bool empty();
	virtual bool full();
};

#endif // STACK_H