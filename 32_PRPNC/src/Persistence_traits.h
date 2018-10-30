#include <fstream>
#include <iostream>

using namespace std;

#ifndef INC_41_TRAITS_PERSISTENCE_TRAITS_H
#define INC_41_TRAITS_PERSISTENCE_TRAITS_H

template<typename T, typename C>
struct Persistence_traits {
    static void write(ofstream &o, C &cont) {
        for (const T &elem : cont) {
            o << elem << endl;
        }
    }

    static void read(ifstream &i, C &cont) {
        for(;;) {
            T x;
            auto it = cont.end();
            i >> x;
            if (!i.good()) {
                break;
            }
            cont.insert(it, x);
        }
    }
};

#endif //INC_41_TRAITS_PERSISTENCE_TRAITS_H