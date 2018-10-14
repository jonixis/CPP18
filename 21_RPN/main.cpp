#include "RPN_calculator.hpp"
#include <sstream>
#include <iostream>
#include <string>


using namespace std;

void print_help() {
    cout << "Usage: 21_RPN [notation]" << endl;
    cout << "\tnotation:" << endl;
    cout << "\t\tn number puts number on stack" << endl;
    cout << "\t\td\t pop number from stack" << endl;
    cout << "\t\t+\t add last two numbers" << endl;
    cout << "\t\t-\t substract last two numbers" << endl;
    cout << "\t\t*\t multiply last two numbers" << endl;
    cout << "\t\t/\t divide last two numbers" << endl;
    cout << "\t\tmin\t select smaller number of the last two" << endl;
    cout << "\t\tp\t print stack" << endl;

}

int main() {

    RPN_calculator rpn_c;

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
    }
}