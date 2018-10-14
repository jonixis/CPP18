#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

#ifndef INC_41_TRAITS_PVECTOR_HPP
#define INC_41_TRAITS_PVECTOR_HPP

template<typename T>
struct persistence_traits {
    static void write(ofstream &o, const T &elem) {
        o << elem << endl;
    }
};

template<typename T, typename P=persistence_traits<T>>
class Pvector {
    string filename;
    vector<T> v;

    void read_vector() {
        ifstream ifs(filename);
        for (;;) {
            T x;
            ifs >> x;
            if (!ifs.good()) {
                break;
            }
            v.push_back(x);
        }
    }

    void write_vector() {
        ofstream ofs(filename);
        for (const T &elem : v) {
            persister::write(ofs, elem);
        }
    }

public:
    typedef P persister;

    explicit Pvector(string fname) : filename(fname) {
        read_vector();
    }

    ~Pvector() {
        write_vector();
        cout << "Destructor called!" << endl;
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

#endif //INC_41_TRAITS_PVECTOR_HPP
