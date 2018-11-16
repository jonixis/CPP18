#include <iostream>
#include "UnlimitedStack.h"
#include "Stack.h"

void fillTestByRef(Stack& s) {
	s.push(99);
	s.push(99);
	s.push(99);
}

void fillTestByCopy(Stack s) {
	s.push(99);
	s.push(99);
	s.push(99);
}

int main(int argc, char const *argv[])
{
	Stack stack;
	UnlimitedStack unlimStack;
	int numbers = 256;

	for (int i = 0; i < numbers; i++) {
		stack.push(i);
		unlimStack.push(i);
	}

	fillTestByRef(stack);
	fillTestByRef(unlimStack);

	// fillTestByCopy(stack);
	// fillTestByCopy(unlimStack);


	std::cout << "Stack:" << std::endl;
	for (int i = 0; i < numbers+3; i++) {
		std::cout << stack.pop() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Unlimited Stack:" << std::endl;
	for (int i = 0; i < numbers+3; i++) {
		std::cout << unlimStack.pop() << std::endl;
	}



	return 0;
}