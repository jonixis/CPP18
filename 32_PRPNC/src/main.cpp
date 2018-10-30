#include "PRPN_calculator.h"
#include "Fraction.h"
#include <complex>

int main() {
    PRPN_calculator<complex<double>> calculator("pvector.txt");
    calculator.run();
}