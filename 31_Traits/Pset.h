#include <set>
#include <fstream>
#include <iostream>
#include "Persistence_traits.h"

using namespace std;

#ifndef INC_41_TRAITS_PSET_H
#define INC_41_TRAITS_PSET_H

template<typename T, typename P=Persistence_traits<T, set<T>>>
class Pset {
    string filename;
    set<T> s;

    void read_set() {
        ifstream ifs(filename);
        persister::read(ifs, s);
    } 

    void write_set() {
        ofstream ofs(filename);
        persister::write(ofs, s);
    }

public:
    typedef P persister;

    explicit Pset(string fname) : filename(fname) {
        read_set();
    }

    ~Pset() {
        write_set();
        cout << "Pset: Destructor called!" << endl;
    }

    void insert_back(const T &el) {
        s.insert(s.end(), el);
    }

    void erase_back() {
        s.erase(s.end());
    }

    long getSize() {
        return s.size();
    }

    void printSet() {
        auto it = s.begin();
        while(it != s.end()) {
            cout << *it << endl;
            it++;
        }
    }
};

#endif //INC_41_TRAITS_PSET_H
