#include "UnlimitedStack.h"
#include <algorithm>
#include <iterator>


UnlimitedStack::UnlimitedStack() { }
UnlimitedStack::~UnlimitedStack() { }

void UnlimitedStack::push(int i) {
	this->v.push_back(i);
}

int UnlimitedStack::pop() {
	int popped = this->v.back();
	this->v.pop_back();
	return popped;
}

bool UnlimitedStack::empty() {
	return this->v.empty();
}

bool UnlimitedStack::full() {
	return false;
}
