#ifndef INC_11_FRACTION_FRACTION_HPP
#define INC_11_FRACTION_FRACTION_HPP

#include <iostream>

class Fraction {
    int counter, denominator;

    friend std::istream &operator>>(std::istream &is, Fraction &f);
    friend std::ostream &operator<<(std::ostream &os, Fraction f);

public:
    Fraction(int c=0, int d=1);

    int get_counter();
    int get_denominator();

    Fraction operator+(Fraction b);
    Fraction operator-(Fraction b);
    Fraction operator*(Fraction b);
    Fraction operator/(Fraction b);
    bool operator<(Fraction b);
    bool operator>(Fraction b);
};

#endif //INC_11_FRACTION_FRACTION_HPP
