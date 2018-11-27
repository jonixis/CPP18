#include "PRPN_calculator.h"
#include "Fraction.h"
#include "FileLocker.h"

int main() {
		string fileName = "pvector.txt";

		PRPN_calculator<double> calculator(fileName);
    calculator.run();

		// FileLocker lock(fileName);
		// for(;;) { }
}
