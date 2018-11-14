#include <vector>
#include "Stack.h"

class UnlimitedStack : public Stack
{
	std::vector<int> stack;
	UnlimitedStack();

public:
	virtual void push(int i);
	virtual int pop();
	virtual bool empty();
	virtual bool full();
	virtual void resizeStack();
};
