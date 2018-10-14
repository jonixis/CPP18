#include <iostream>
#include "PRPN_calculator.h"

PRPN_calculator::PRPN_calculator() {

}

void PRPN_calculator::push(double n) {
    stack.push_back(n);
}

double PRPN_calculator::pop() {
    double n = stack.back();
    stack.pop_back();

    return n;
}

void PRPN_calculator::print_stack() {
    std::cout << std::endl;
    std::cout << "------ Current Stack ------" << std::endl;
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        std::cout << it - stack.begin() + 1  << ": " << *it << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
    std::cout << std::endl;
}

void PRPN_calculator::add() {
    if (!stack_big_enough()) {
        return;
    }

    double x = pop();
    double y = pop();

    push(y+x);
}

void PRPN_calculator::sub() {
    if (!stack_big_enough()) {
        return;
    }

    double x = pop();
    double y = pop();

    push(y-x);
}

void PRPN_calculator::mul() {
    if (!stack_big_enough()) {
        return;
    }

    double x = pop();
    double y = pop();

    push(y*x);
}

void PRPN_calculator::div() {
    if (!stack_big_enough()) {
        return;
    }

    double x = pop();
    double y = pop();

    push(y/x);
}

void PRPN_calculator::my_min() {
    if (!stack_big_enough()) {
        return;
    }
    double x = pop();
    double y = pop();

    push(std::min(x, y));
}

bool PRPN_calculator::stack_big_enough() {
    if (stack.size() >= 2) {
        return true;
    } else {
        std::cout << "You need at least two numbers on stack!" << std::endl;
        return false;
    }
}