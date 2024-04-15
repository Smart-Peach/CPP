#include "UnaryOperation.hpp"
#include "../Mult.cpp"

class Exponent: public UnaryOpperation {

public:
    Exponent(Expression* op) : UnaryOperation(op) {}
    Exponent(const Exponent& other): operand(other.operand) {}

    Expression* diff(std::string var) override {
        return new Mult(new Exponent(this*), operand->diff());
    }

    std::string to_string() const override {
        return "e^(" + operand->to_string() + ")";
    }
}