#pragma once

#include "BinaryOperation.hpp"
#include "Add.cpp"
#include "Sub.cpp"
#include "Mult.cpp"

class Div: public BinaryOperation {

public:
    Div(Expression* l, Expression* r) : BinaryOperation(l, r, "/") {}

    Expression* diff(std::string var) override {
        // (a / b)' = (a'*b - a*b') / (b * b)
        return new Div(new Sub(new Mult(left->diff(var), right), new Mult(left, right->diff(var))), new Mult(right, right));
    }
};