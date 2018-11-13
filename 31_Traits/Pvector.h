#include <vector>
#include <fstream>
#include <iostream>
#include "Persistence_traits.h"

using namespace std;

#ifndef INC_41_TRAITS_PVECTOR_H
#define INC_41_TRAITS_PVECTOR_H

template<typename T, typename P=Persistence_traits<T, vector<T>>>
class Pvector {
    string filename;
    vector<T> v;

    void read_vector() {
        ifstream ifs(filename);
        persister::read(ifs, v);
    } 

    void write_vector() {
        ofstream ofs(filename);
        persister::write(ofs, v);
    }

public:
    typedef P persister;

    explicit Pvector(string fname) : filename(fname) {
        read_vector();
    }

    ~Pvector() {
        write_vector();
        cout << "Pvector: Destructor called!" << endl;
    }

    void push_back(const T &el) {
        v.push_back(el);
    }
    void pop_back() {
        v.pop_back();
    }

    long getSize() {
        return v.size();
    }

    void printElement(int index) {
        cout << v.at(index) << endl;
    }
};

#endif //INC_41_TRAITS_PVECTOR_H
