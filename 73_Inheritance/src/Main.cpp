#include "ClassC.h"

void foo() {
	ClassC classC;
}

int main(int argc, char const *argv[]) {

	foo();
	// First the highest parent class constructor is called. And then the constructors of all classes in between.
	// A -> B -> C
	// Destructing workd the other way around.
	// C -> B -> A
	return 0;
}
