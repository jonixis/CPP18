#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int c, int d) : counter(c), denominator(d) { }

int Fraction::get_counter() {
    return counter;
}

int Fraction::get_denominator() {
    return denominator;
}

int gcf(int a, int b) {
    return b == 0 ? a : gcf(b, a%b);
}

int lcm(int a, int b) {
    return (a * b) / gcf(a,b);
}

Fraction Fraction::operator+(Fraction b) {
    int newDenom = lcm(denominator, b.get_denominator());
    int newCounter = counter*(newDenom/denominator) + b.get_counter()*(newDenom/b.get_denominator());

    return Fraction(newCounter,newDenom);
}

Fraction Fraction::operator-(Fraction b) {
    int newDenom = lcm(denominator, b.get_denominator());
    int newCounter = counter*(newDenom/denominator) - b.get_counter()*(newDenom/b.get_denominator());

    return Fraction(newCounter,newDenom);
}

Fraction Fraction::operator*(Fraction b) {
    int x = gcf(counter, b.get_denominator());
    int y = gcf(b.get_counter(), denominator);

    int newCounter = (counter / x) * (b.get_counter() / y);
    int newDenom = (denominator / y) * (b.get_denominator() / x);

    return Fraction(newCounter,newDenom);
}

bool Fraction::operator<(Fraction b) {
    int newDenom = lcm(denominator, b.get_denominator());

    return newDenom * counter < newDenom * b.get_counter();
}   

bool Fraction::operator>(Fraction b) {
    int newDenom = lcm(denominator, b.get_denominator());

    return newDenom * counter > newDenom * b.get_counter();
}

Fraction Fraction::operator/(Fraction b) {
    int x = gcf(counter, b.get_counter());
    int y = gcf(b.get_denominator(), denominator);

    int newCounter = (counter / x) * (b.get_denominator() / y);
    int newDenom = (denominator / y) * (b.get_counter() / x);

    return Fraction(newCounter,newDenom);
}

inline void check_char(std::istream &is, char ch) {
    char c;
    is >> c;

    if (c!=ch) {
        is.putback(c);
        is.setstate(std::ios::badbit);
    }
}

std::istream &operator>>(std::istream &is, Fraction &f) {
    Fraction g;
    check_char(is,'(');
    is >> g.counter;
    check_char(is,'/');
    is >> g.denominator;
    check_char(is,')');

    if (is) {
        f=g;
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, Fraction f) {
    os << '(' << f.counter << '/' << f.denominator << ')';
    return os;
}


