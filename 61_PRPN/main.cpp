#include <sstream>
#include <iostream>
#include <string>
#include "PRPN_calculator.h"

using namespace std;

void print_help() {
    cout << "Available commands:" << endl;
    cout << "\tn number puts number on stack" << endl;
    cout << "\td\t pop number from stack" << endl;
    cout << "\t+\t add last two numbers" << endl;
    cout << "\t-\t substract last two numbers" << endl;
    cout << "\t*\t multiply last two numbers" << endl;
    cout << "\t/\t divide last two numbers" << endl;
    cout << "\tmin\t select smaller number of the last two" << endl;
    cout << "\tp\t print stack" << endl;
    cout << "\tq\t quit" << endl;
    cout << "\th\t show this help" << endl;
}

int main() {
    PRPN_calculator rpn_c;

    cout << endl;
    cout << "Welcome to the CLI Reverse Polish Notation Calculator" << endl;
    cout << "Type 'q' to quit or 'h' for help" << endl << endl;

    for(;;) {
        string input;
        double number;

        cout << ">";
        getline(cin, input);
        istringstream iss(input);

        while (iss) {
            string s;
            iss >> s;

            if (s == "n") {
                iss >> number;
                rpn_c.push(number);
            }
            else if (s == "+") {
                rpn_c.add();
            }
            else if (s == "-") {
                rpn_c.sub();
            }
            else if (s == "*") {
                rpn_c.mul();
            }
            else if (s == "/") {
                rpn_c.div();
            }
            else if (s == "min") {
                rpn_c.my_min();
            }
            else if (s == "p") {
                rpn_c.print_stack();
            }
            else if (s == "h") {
                print_help();
            }
            else if (s == "q") {
                return 0;
            }
            else if (s == " " || s.empty()) {
                /*nop*/
            }
            else {
                cout << "Invalid command found! Type 'h' for help" << endl;
            }
        }
        
        rpn_c.print_stack();
    }
}