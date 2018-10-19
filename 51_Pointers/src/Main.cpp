#include <iostream>
#include <vector>
#include "Dumb_pointer.h"
#include "Smart_pointer.h"

using namespace std;

void print(Smart_pointer<vector<double>> p) {
	cout << "Counter: " << p.get_counter() << ", " << "Size of vector: " << p->size() << endl;
}

void dumb_pointer_test() {
	auto *foo = new vector<int>();
	foo->push_back(10);
	foo->push_back(20);
	foo->push_back(30);
	foo->push_back(40);

	Dumb_pointer<vector<int>> p(foo);

	cout << "Dumb pointer test: ";
	if (p->size() == foo->size()) {
		cout << "\u2705" << endl;
	} else {
		cout << "\u274C" << endl;
	}
}

void smart_pointer_test() {
	auto *foo = new vector<double>();
	foo->push_back(0.1);
	foo->push_back(0.2);

	auto *bar = new vector<double>();
	bar->push_back(0.3);
	bar->push_back(0.4);
	bar->push_back(0.5);

	Smart_pointer<vector<double>> p(foo);
	cout << "Counter of P: " << p.get_counter() << endl;

	Smart_pointer<vector<double>> q(p);
	cout << "Counter of P: " << p.get_counter() << endl;
	cout << "Counter of Q: " << q.get_counter() << endl;
	
	Smart_pointer<vector<double>> r(bar);
	cout << "Counter of R: " << r.get_counter() << endl;

	q = r;

	cout << "Counter of P: " << p.get_counter() << endl;
	cout << "Counter of Q: " << q.get_counter() << endl;
	cout << "Counter of R: " << r.get_counter() << endl;

	print(p);
	print(q);
	print(r);

	cout << "Size vector of P: " << p->size() << " Size vector of R: " << r->size() << endl;
	cout << "Size vector of P: " << p->size() << " Size vector of Q: " <<  q->size() << " Size vector of R: " << r->size() << endl;
}

int main(int argc, char *argv[]) {
	dumb_pointer_test();	
	smart_pointer_test();

	return 0;
}