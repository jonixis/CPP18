#include <iostream>
#include "Pvector.h"
#include "Pset.h"

using namespace std;

void foo(Pvector<int> *pv) {

    pv->push_back(pv->getSize());

    for (int i = 0; i < pv->getSize(); i++) {
        pv->printElement(i);
    }
}

void bar(Pset<string> *ps) {

	ps->insert_back("zookie" + to_string(ps->getSize()));

	ps->printSet();
}

int main() {
	cout << "----- Pvector -----" << endl;

    Pvector<int> pv("pvector-int.txt");
    foo(&pv);

    cout << "----- Pset -----" << endl;

    Pset<string> ps("pset-string.txt");
    bar(&ps);

    return 0;
}