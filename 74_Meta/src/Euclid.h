#ifndef EUCLID_H
#define EUCLID_H

template<int A, int B> struct euclid {
	static const int res = euclid<B, A%B>::res;
};

template<int A> struct euclid<A, 0> {
	static const int res = A;
};

constexpr int euclidConst(int a, int b) {
    return b == 0 ? a : euclidConst(b, a%b);
}

#endif
