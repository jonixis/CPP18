#ifndef INC_41_TRAITS_PVECTOR_H
#define INC_41_TRAITS_PVECTOR_H

#include "Persistence_traits.h"
#include "FileLocker.h"
#include <fstream>
#include <iostream>
#include <vector>

template <typename T, typename P = persistence_traits<T>>
class Pvector : public std::vector<T>{
  std::string filename;

  void read_vector() {
		FileLocker lock(filename);
		// Return if file could not be locked
		if (lock.isLocked() != 0) {
			std::cout << "Pvector not read. Could not get a file lock." << std::endl;
			return;
		}

    std::ifstream ifs(filename);
    for (;;) {
      T t;
      persister::read(ifs, t);
      if (!ifs.good()) {
        break;
      }
      std::vector<T>::push_back(t);
    }
  }

  void write_vector() {
		FileLocker lock(filename);
		// Return if file could not be locked
		if (lock.isLocked() != 0) {
			std::cout << "Pvector not written. Could not get a file lock." << std::endl;
			return;
		}

    std::ofstream ofs(filename);
    for (const T &elem : *this) {
      persister::write(ofs, elem);
    }
  }

public:
  typedef P persister;

  explicit Pvector(std::string fname) : filename(fname) {
		read_vector();
	}

  ~Pvector() {
    write_vector();
  }
};

#endif // INC_41_TRAITS_PVECTOR_H
