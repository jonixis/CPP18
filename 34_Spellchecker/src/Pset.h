#ifndef INC_41_TRAITS_PSET_H
#define INC_41_TRAITS_PSET_H

#include "Persistence_traits.h"
#include <fstream>
#include <iostream>
#include <set>

template <typename T, typename P = persistence_traits<T>> 
class Pset : public std::set<T> {
  std::string filename;

  void read_set() {
    std::ifstream ifs(filename);
    for (;;) {
      T t;
      persister::read(ifs, t);
      if (!ifs.good()) {
        break;
      }
      std::set<T>::insert(t);
    }
  }

  void write_set() {
    std::ofstream ofs(filename);
    for (const T &elem : *this) {
      persister::write(ofs, elem);
    }
  }

public:
  typedef P persister;

  explicit Pset(std::string fname) : filename(fname) { 
    read_set();
  }

  ~Pset() {
    write_set();
  }

  void printSet() {
    auto it = std::set<T>::begin();
    while (it != std::set<T>::end()) {
      std::cout << *it << std::endl;
      it++;
    }
  }
};

#endif // INC_41_TRAITS_PSET_H
