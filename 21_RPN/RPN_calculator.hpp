//
// Created by Jonathan Stahl on 03.10.18.
//

#ifndef INC_21_RPN_RPN_CALCULATOR_HPP
#define INC_21_RPN_RPN_CALCULATOR_HPP

#include <vector>

class RPN_calculator {
    std::vector<double> stack;

public:
    RPN_calculator();

    void push(double n);
    double pop();
    void print_stack();
    void add();
    void sub();
    void mul();
    void div();
    void my_min();
    bool stack_big_enough();
};


#endif //INC_21_RPN_RPN_CALCULATOR_HPP
