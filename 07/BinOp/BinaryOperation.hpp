#pragma once

#include "../Expression.hpp"

class BinaryOperation: public Expression {

protected:
    Expression* left;
    Expression* right;
    std::string operation;

public:
    BinaryOperation(Expression* l, Expression* r, std::string op) : left(l), right(r), operation(op) {}
    BinaryOperation(const BinaryOperation& other): left(other.left), right(other.right), operation(other.operation) {}

    ~BinaryOperation() {
        delete left;
        delete right;
    }

    std::string to_string() const override {
        return "(" + left->to_string() + " " + operation + " " + right->to_string() + ")";
    }


};