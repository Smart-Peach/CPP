#include "UnaryOperation.hpp"
#include "../BinOp/Mult.cpp"

class Exponent: public UnaryOperation {

public:
    Exponent(Expression* op) : UnaryOperation(op) {}

    Expression* diff(std::string var) override {
        return new Mult(this, operand->diff(var));
    }

    std::string to_string() const override {
        return "e^(" + operand->to_string() + ")";
    }
};