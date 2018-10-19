#include <iostream>

#ifndef _51_POINTERS_DUMB_POINTER_H
#define _51_POINTERS_DUMB_POINTER_H

template<typename T>
class Dumb_pointer
{
	T *p;
public:
	Dumb_pointer(T *t) : p(t) { }
	
	~Dumb_pointer() {
		delete p;
	}

	T& operator*() {
		return *p;
	}

	T* operator->() {
		return p;
	}
};

#endif // _51_POINTERS_DUMB_POINTER_H