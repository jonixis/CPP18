#include "ClassA.h"
#include <iostream>

ClassA::ClassA() {
	std::cout << "Constructor ClassA" << std::endl;
}

ClassA::~ClassA() {
	std::cout << "Destructor ClassA" << std::endl;
}
