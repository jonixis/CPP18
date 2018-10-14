//
// Created by Jonathan Stahl on 03.10.18.
//

#include "RPN_calculator.hpp"

#include <iostream>

RPN_calculator::RPN_calculator() {

}

void RPN_calculator::push(double n) {
    stack.push_back(n);
}

double RPN_calculator::pop() {
    double n = stack.back();
    stack.pop_back();

    return n;
}

void RPN_calculator::print_stack() {
   for (auto it = stack.begin(); it != stack.end(); ++it) {
       std::cout << it - stack.begin() + 1  << ": " << *it << std::endl;
   }
}

void RPN_calculator::add() {
    if (!stack_big_enough()) {
        return;
    }

    double x = pop();
    double y = pop();

    push(y+x);
}

void RPN_calculator::sub() {
    if (!stack_big_enough()) {
        return;
    }

    double x = pop();
    double y = pop();

    push(y-x);
}

void RPN_calculator::mul() {
    if (!stack_big_enough()) {
        return;
    }

    double x = pop();
    double y = pop();

    push(y*x);
}

void RPN_calculator::div() {
    if (!stack_big_enough()) {
        return;
    }

    double x = pop();
    double y = pop();

    push(y/x);
}

void RPN_calculator::my_min() {
    if (!stack_big_enough()) {
        return;
    }
    double x = pop();
    double y = pop();

    push(std::min(x, y));
}

bool RPN_calculator::stack_big_enough() {
    if (stack.size() >= 2) {
        return true;
    } else {
        std::cout << "You need at least two numbers on stack!" << std::endl;
        return false;
    }
}