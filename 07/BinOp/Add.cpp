#include "BinaryOperation.hpp"

class Add: public BinaryOpperation {

public:
    Add(Expression* l, Expression* r) : BinaryOpperation(l, r, "+") {}

    Expression* diff(std::string var) override {
        return new Add(left->diff(var), right->diff(var));
    }
}