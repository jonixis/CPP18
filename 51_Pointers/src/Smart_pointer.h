#include <iostream> 

#ifndef _51_POINTERS_SMART_POINTER
#define _51_POINTERS_SMART_POINTER
 
template <typename T>
class Smart_pointer
{
	T *pointer;
	int *counter;

public:
	Smart_pointer(T *p): pointer(p) {
		counter = new int(1);
		
	}
	Smart_pointer(Smart_pointer<T> &p): pointer(p.pointer), counter(p.counter) {
		(*counter)++;
	}

	~Smart_pointer() {
		std::cout << "Destructor counter: " << *counter << std::endl;
		if (--(*counter) <= 0) {
			std::cout << "DESCTRUCTED" << std::endl;
			delete pointer;
			delete counter;
		}
	}

	T& operator*() {
		return *pointer;
	}

	T* operator->() {
		return pointer;
	}

	Smart_pointer<T>& operator=(Smart_pointer<T>& p) {
		if (this == &p) {
			return *this;
		}

		std::cout << "Destructor counter: " << *counter << std::endl;
		if (--(*counter) <= 0) {
			std::cout << "DESCTRUCTED" << std::endl;
			delete pointer;
			delete counter;
		}

		pointer = p.pointer;
		counter = p.counter;

		(*counter)++;

		return *this;
	}

	int get_counter() {
		return *counter;
	}

	
};

#endif // _51_POINTERS_SMART_POINTER