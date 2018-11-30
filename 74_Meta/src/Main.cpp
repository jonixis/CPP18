#include "Fibonacci.h"
#include "Euclid.h"
#include <iostream>

int main(int argc, char const *argv[]) {
	int resFib = fibonacci<10>::res;
	int resGCD = euclid<1071, 462>::res;

	int resFibConst = fibonacciConst(10);
	int resGCDConst = euclidConst(1071, 462);

	std::cout << "Fibonacci: " << resFib << std::endl;
	std::cout << "Euclid: " << resGCD << std::endl;

	std::cout << "FibonacciConst: " << resFibConst << std::endl;
	std::cout << "EuclidConst: " << resGCDConst << std::endl;


	return 0;
}
