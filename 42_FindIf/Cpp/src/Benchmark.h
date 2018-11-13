#ifndef FIND_IF_BENCHMARK_H
#define FIND_IF_BENCHMARK_H

#include <vector>
#include <iostream>

template<typename T>
class Benchmark
{
public:
  typedef typename std::vector<T>::iterator iterator;

  Benchmark(int _vectorSize, T _element) : myVector(_vectorSize - 1), element(_element) {
    this->myVector.push_back(this->element);
  }
  ~Benchmark() { }

  iterator execute() {
    return find_if(myVector.begin(), myVector.end(), [&](T& x) {
      return x == this->element;
    });
  }

  void printMyVector() {
    for (T& elem : myVector) {
      std::cout << elem << std::endl;
    }
  }
  
private:
  std::vector<T> myVector;
  T element;
};

#endif // FIND_IF_BENCHMARK_H