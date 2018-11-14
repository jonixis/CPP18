#include "UnlimitedStack.h"

UnlimitedStack::UnlimitedStack() : size(0) { }

void UnlimitedStack::push(int i) {
	if (Stack::full()) {
		resizeStack();
	}
}

void UnlimitedStack::resizeStack() {
	int* temp[2];
	s = temp;
}