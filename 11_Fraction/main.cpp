#include <iostream>
#include "Fraction.hpp"

using namespace std;

void print_help() {
    cout << "Usage: 11_fraction [options]" << endl;
    cout << "\toptions:" << endl;
    cout << "\t\t-i interactive mode" << endl;
    cout << "\t\t-t test script" << endl;
    cout << "\t\t-h show help" << endl;

}

void test_mode() {
    cout << "Test toy examples...\n" << endl;

    Fraction f(3,5);
    Fraction g(2,6);

    cout << "Fraction f: " << f << endl;
    cout << "Fraction g: " << g << endl;

    cout << "\n" << f << " + " << g << " = " << f+g << endl;
    cout << "\n" << f << " - " << g << " = " << f-g << endl;
    cout << "\n" << f << " * " << g << " = " << f*g << endl;
    cout << "\n" << f << " / " << g << " = " << f/g << endl;


    cout << "\nTest complete!" << endl;
}

void interactive_mode() {
    cout << "Interactive mode activated" << endl;
    cout << "\nExample: (3/5) * (2/6)\n" << endl;

    for(;;) {
        Fraction f, g;
        string op;

        cout << ">";

        cin >> f >> op >> g;

        cout << " = ";

        if (op == "+") {
            cout << f + g << endl;
        }
        else if (op == "-") {
            cout << f - g << endl;
        }
        else if (op == "*") {
            cout << f * g << endl;
        }
        else if (op == "/") {
            cout << f / g << endl;
        }
        else {
            cout << "Unknown operator" << endl;
        }

        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    cout << "Welcome to the CLI Fraction Calculator\n" << endl;

    if (argc <= 1) {
        print_help();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            interactive_mode();
        }
        else if (strcmp(argv[i], "-t") == 0) {
            test_mode();
        }
        else if (strcmp(argv[i], "-h") == 0) {
            print_help();
        }
        else {
            print_help();
            return 1;
        }
    }


    return 0;
}