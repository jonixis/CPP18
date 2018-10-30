#include <vector>
#include <iostream>
#include <sstream>
#include "Pvector.h"

using namespace std;

#ifndef INC_61_PRPN_CALCULATOR_H
#define INC_61_PRPN_CALCULATOR_H

template<typename T>
class PRPN_calculator {
    Pvector<T> stack;

public:
    PRPN_calculator(string filepath);

    void push(T n);
    T pop();
    void print_stack();
    void add();
    void sub();
    void mul();
    void div();
    // void my_min();
    bool stack_big_enough();
    void print_help();
    int run();
};

#endif //INC_61_PRPN_CALCULATOR_H

/***Template Definition***/

template<typename T>
PRPN_calculator<T>::PRPN_calculator(string filepath) : stack(filepath) { }

template<typename T>
void PRPN_calculator<T>::push(T n) {
    stack.push_back(n);
}

template<typename T>
T PRPN_calculator<T>::pop() {
    return stack.pop_back();
}

template<typename T>
void PRPN_calculator<T>::print_stack() {
    std::cout << std::endl;
    std::cout << "------ Current Stack ------" << std::endl;
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        std::cout << it - stack.begin() + 1  << ": " << *it << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
    std::cout << std::endl;
}

template<typename T>
void PRPN_calculator<T>::add() {
    if (!stack_big_enough()) {
        return;
    }

    T x = pop();
    T y = pop();

    push(y+x);
}

template<typename T>
void PRPN_calculator<T>::sub() {
    if (!stack_big_enough()) {
        return;
    }

    T x = pop();
    T y = pop();

    push(y-x);
}

template<typename T>
void PRPN_calculator<T>::mul() {
    if (!stack_big_enough()) {
        return;
    }

    T x = pop();
    T y = pop();

    push(y*x);
}

template<typename T>
void PRPN_calculator<T>::div() {
    if (!stack_big_enough()) {
        return;
    }

    T x = pop();
    T y = pop();

    push(y/x);
}

// template<typename T>
// void PRPN_calculator<T>::my_min() {
//     if (!stack_big_enough()) {
//         return;
//     }
//     T x = pop();
//     T y = pop();

//     if (x < y) {
//         push(x);
//     } else {
//         push(y);
//     }
// }

template<typename T>
bool PRPN_calculator<T>::stack_big_enough() {
    if (stack.getSize() >= 2) {
        return true;
    } else {
        std::cout << "You need at least two numbers on stack!" << std::endl;
        return false;
    }
}

template<typename T>
void PRPN_calculator<T>::print_help() {
    cout << "Available commands:" << endl;
    cout << "\tn number puts number on stack" << endl;
    cout << "\td\t pop number from stack" << endl;
    cout << "\t+\t add last two numbers" << endl;
    cout << "\t-\t substract last two numbers" << endl;
    cout << "\t*\t multiply last two numbers" << endl;
    cout << "\t/\t divide last two numbers" << endl;
    // cout << "\tmin\t select smaller number of the last two" << endl;
    cout << "\tp\t print stack" << endl;
    cout << "\tq\t quit" << endl;
    cout << "\th\t show this help" << endl;
}

template<typename T>
int PRPN_calculator<T>::run() {
    cout << endl;
    cout << "Welcome to the CLI Reverse Polish Notation Calculator" << endl;
    cout << "Type 'q' to quit or 'h' for help" << endl << endl;

    for(;;) {
        string input;
        T number;

        cout << ">";
        getline(cin, input);
        istringstream iss(input);

        while (iss) {
            string s;
            iss >> s;

            if (s == "n") {
                iss >> number;
                push(number);
                print_stack();
            }
            else if (s == "d") {
                pop();
                print_stack();
            }
            else if (s == "+") {
                add();
                print_stack();
            }
            else if (s == "-") {
                sub();
                print_stack();
            }
            else if (s == "*") {
                mul();
                print_stack();
            }
            else if (s == "/") {
                div();
                print_stack();
            }
            // else if (s == "min") {
            //     my_min();
            //     print_stack();
            // }
            else if (s == "p") {
                print_stack();
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
