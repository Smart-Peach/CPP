#include "BinaryOperation.hpp"

class Sub: public BinaryOpperation {

public:
    Sub(Expression* l, Expression* r) : BinaryOpperation(l, r, "-") {}

    Expression* diff(std::string var) override {
        return new Sub(left->diff(var), right->diff(var));
    }
}