#include <vector>
#include <iostream>
#include <chrono>
#include "Benchmark.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Benchmark<string> benchmark(50000000, "foo");

  auto start = std::chrono::high_resolution_clock::now();
  auto it = benchmark.execute();
  auto finish = std::chrono::high_resolution_clock::now();

  double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000000.0;

  cout << "=== Benchmark result ====" << endl;
  cout << "Found element '" << *it << "' in: " << elapsed << " seconds" << endl;


  // benchmark.printMyVector();

  return 0;
}