#include "PRPN_calculator.h"
#include "Fraction.h"

int main() {
    PRPN_calculator<Fraction> calculator("tmp/pvector.txt");
    calculator.run();
}