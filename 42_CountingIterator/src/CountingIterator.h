#ifndef COUNTING_ITERATOR_COUNTING_ITERATOR_H
#define COUNTING_ITERATOR_COUNTING_ITERATOR_H

#include <iterator>
// #include <iostream>

template<typename T>
class CountingIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{

	T t;

public:
	CountingIterator(T _t = 0) : t(_t) {

	}

	CountingIterator& operator++() {
		++t;
		return *this;
	}

	CountingIterator& operator++(int) {
		CountingIterator it = *this;
		++(*this);
		return it;
	}

	CountingIterator& operator--() {
		--t;
		return *this;
	}

	CountingIterator& operator--(int) {
		CountingIterator it = *this;
		--(*this);
		return it;
	}

	bool operator==(CountingIterator other) const {
		// std::cout << "t: " << t << " | other.t: " << other.t << std::endl;
		return t == ++other.t;
	}

	bool operator!=(CountingIterator other) const {
		return !(*this == other);
	}

	T operator*() const {
		return t;
	}
};

template<typename T>
CountingIterator<T> counter(const T &t) {
	return CountingIterator<T>(t);
}

#endif // COUNTING_ITERATOR_COUNTING_ITERATOR_H