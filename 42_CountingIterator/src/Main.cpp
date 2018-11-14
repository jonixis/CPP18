#include <vector>
#include <iostream>
#include "CountingIterator.h"

using namespace std;

void foo(void) {
	cout << endl;

	// Create vector with ints from [0..10]
	vector<int> v(counter(0), counter(10));

	cout << "Vecotor v: ";
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
	cout << endl;

	cout << "for_each(counter(10), counter(20, print): " << endl;
	// Print ints from [10..20]
	for_each(counter(10), counter(20), [](int i){
		cout << i << endl;
	});
}

int main(int argc, char const *argv[])
{

	foo();

	return 0;
}