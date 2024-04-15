#pragma once

#include "Expression.hpp"
#include "Val.cpp"

class Var: public Expression {
    std::string name;

public:
    Var(std::string var_name) : name(var_name){}
    Var(const Var& other): name(other.name) {}

    Expression* diff(std::string var) override {
        if (var == name) {
            return new Val(1);
        }
        return new Val(0);
    }

    std::string to_string() const override {
        return name;
    }
};