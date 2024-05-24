#pragma once

#include <iostream>
#include <string>


class Expression {
public:
    virtual ~Expression() {};

    virtual Expression* diff(std::string var) = 0;
    virtual std::string to_string() const = 0;
    virtual Expression* copy() = 0;
};


class UnaryOperation: public Expression {
protected:
    Expression* operand;

public:
    UnaryOperation(Expression* op) : operand(op) {}
    UnaryOperation(const UnaryOperation& other) : operand(other.operand) {}
    ~UnaryOperation() {
        delete operand;
    }
};


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