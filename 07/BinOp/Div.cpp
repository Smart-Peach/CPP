#include "BinaryOperation.hpp"
#include "Add.cpp"
#include "Sub.cpp"
#include "Mult.cpp"

class Div: public BinaryOpperation {

public:
    Div(Expression* l, Expression* r) : BinaryOpperation(l, r, "/") {}

    Expression* diff(std::string var) override {
        // (a / b)' = (a'*b - a*b') / (b * b)
        return new Div(new Sub(new Mult(left->diff(), right), new Mult(left, right->diff())), new Mult(right, right));
    }
}