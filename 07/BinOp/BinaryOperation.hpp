#include "../Expression.hpp"

class BinaryOpperation: public Expression {

protected:
    Expression* left;
    Expression* right;
    std::string operation;

public:
    BinaryOpperation(Expression* l, Expression* r, std::string op) : left(l), right(r), operation(op) {}
    BinaryOperation(const BinaryOperation& other): left(other.left), right(other.right), operation(other.operation) {}

    ~BinaryOpperation() {
        delete left;
        delete right;
    }

    std::string to_string() const override {
        return "(" + left->to_string() + " " + operation + " " + right->to_string() + ")";
    }


}