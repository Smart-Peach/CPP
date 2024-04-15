#pragma once

#include "BinaryOperation.hpp"

class Sub: public BinaryOperation {

public:
    Sub(Expression* l, Expression* r) : BinaryOperation(l, r, "-") {}

    Expression* diff(std::string var) override {
        return new Sub(left->diff(var), right->diff(var));
    }
};