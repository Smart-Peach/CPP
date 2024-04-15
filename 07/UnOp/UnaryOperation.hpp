#pragma once

#include "../Expression.hpp"

class UnaryOperation: public Expression {

protected:
    Expression* operand;

public:
    UnaryOperation(Expression* op) : operand(op) {}
    ~UnaryOperation() {
        delete operand;
    }
};