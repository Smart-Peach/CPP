#pragma once

#include "Expression.hpp"

class Val: public Expression {

    double value;

public:
    Val(double val) : value(val) {}
    Val(const Val& other): value(other.value) {}
    

    Expression* diff(std::string var) override {
        return new Val(0);
    }

    std::string to_string() const override {
        return std::to_string(value);
    }
};