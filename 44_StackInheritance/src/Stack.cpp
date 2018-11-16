#include "Stack.h"
#include <iostream>

	Stack::Stack() : sp(256) { }
	Stack::~Stack() { }


	void Stack::push(int i) {
		if (full()) {
			std::cout << "Element '" << i << "' could not be pushed. Stack full!" << std::endl;
			return;
		}
		s[--sp] = i;
	}

	int Stack::pop() {
		if (empty()) {
			std::cout << "Stack Empty! Following pops are not from stack!" << std::endl;
		}
		return s[sp++];
	}

	bool Stack::empty() {
		return sp == 256;
	}

	bool Stack::full() {
		return sp == 0;
	}
