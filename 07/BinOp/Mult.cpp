#include "BinaryOperation.hpp"
#include "Add.cpp"

class Mult: public BinaryOpperation {

public:
    Mult(Expression* l, Expression* r) : BinaryOpperation(l, r, "*") {}

    Expression* diff(std::string var) override {
        // (a * b)' = a'*b + a*b'
        return new Add(new Mult(left->diff(), right), new Mult(left, right->diff()));
    }
}