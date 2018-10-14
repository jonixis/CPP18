#include <iostream>
#include "Pvector.hpp"

using namespace std;

void foo(Pvector<int> *pv) {

    for (int i = 0; i < pv->getSize(); i++) {
        pv->printElement(i);
    }

    pv->push_back(17);
}

int main() {
    Pvector<int> pv("pvector-int.txt");
    foo(&pv);
    return 0;
}