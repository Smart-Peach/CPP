#pragma once

#include "BinaryOperation.hpp"
#include "Add.cpp"

class Mult: public BinaryOperation {

public:
    Mult(Expression* l, Expression* r) : BinaryOperation(l, r, "*") {}

    Expression* diff(std::string var) override {
        // (a * b)' = a'*b + a*b'
        return new Add(new Mult(left->diff(var), right), new Mult(left, right->diff(var)));
    }
};