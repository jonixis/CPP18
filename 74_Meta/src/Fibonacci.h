#ifndef FIBONACCI_H
#define FIBONACCI_H

template<int T> struct fibonacci {
	static const int res = fibonacci<T-1>::res + fibonacci<T-2>::res;
};

template<> struct fibonacci<0> {
	static const int res = 0;
};

template<> struct fibonacci<1> {
	static const int res = 1;
};

constexpr int fibonacciConst(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}

	return fibonacciConst(n - 1) + fibonacciConst(n - 2);
}


#endif
