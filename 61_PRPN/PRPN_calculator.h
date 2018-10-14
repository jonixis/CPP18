#ifndef INC_61_PRPN_CALCULATOR_H
#define INC_61_PRPN_CALCULATOR_H

#include <vector>

class PRPN_calculator {
    std::vector<double> stack;

public:
    PRPN_calculator();

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


#endif //INC_61_PRPN_CALCULATOR_H