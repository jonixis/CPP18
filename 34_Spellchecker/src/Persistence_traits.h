#include <fstream>
#include <iostream>

#ifndef INC_41_TRAITS_PERSISTENCE_TRAITS_H
#define INC_41_TRAITS_PERSISTENCE_TRAITS_H

template <typename T>
struct persistence_traits {

  static void read(std::ifstream &ifs, T &elem) { 
    ifs >> elem;
  }
  static void write(std::ofstream &ofs, const T &elem) {
    ofs << elem << std::endl;
  }
};

template <>
struct persistence_traits<std::string> {

  static void read(std::ifstream &ifs, std::string &elem) {
    // std::getline(ifs, elem);
    // Use word by word also for strings
    ifs >> elem;
  }

  static void write(std::ofstream &ofs, const std::string &elem) {
    ofs << elem << std::endl;
  }
};

#endif // INC_41_TRAITS_PERSISTENCE_TRAITS_H