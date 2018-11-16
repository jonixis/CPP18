#ifndef U_STACK_H
#define U_STACK_H

#include "Stack.h"
#include <vector>

class UnlimitedStack : public Stack
{
	std::vector<int> v;
public:
	UnlimitedStack();
	virtual ~UnlimitedStack();

	virtual void push(int i);
	virtual int pop();
	virtual bool empty();
	virtual bool full();
};

#endif // U_STACK_H