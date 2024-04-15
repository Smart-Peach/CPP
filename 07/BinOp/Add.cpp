#pragma once

#include "BinaryOperation.hpp"

class Add: public BinaryOperation {

public:
    Add(Expression* l, Expression* r) : BinaryOperation(l, r, "+") {}

    Expression* diff(std::string var) override {
        return new Add(left->diff(var), right->diff(var));
    }
};