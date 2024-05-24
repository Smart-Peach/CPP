#include "Expressions.hpp"

class Val: public Expression {

    double value;

public:
    Val(double val) : value(val) {}
    Val(const Val& other): value(other.value) {}
    ~Val() {};
    

    Expression* diff(std::string var) override {
        return new Val(0);
    }

    std::string to_string() const override {
        return std::to_string(value);
    }

    Expression* copy() override { return new Val(*this); }
};

class Var: public Expression {

    std::string name;

public:
    Var(std::string var_name) : name(var_name){}
    Var(const Var& other): name(other.name) {}
    ~Var() {};

    Expression* diff(std::string var) override {
        if (var == name) {
            return new Val(1);
        }
        return new Val(0);
    }

    std::string to_string() const override {
        return name;
    }

    Expression* copy() override { return new Var(*this); }

};


class Add: public BinaryOperation {
public:
    Add(Expression* l, Expression* r) : BinaryOperation(l, r, "+") {}
    Add(const Add& other): BinaryOperation(other.left->copy(), other.right->copy(), "+") { }

    Expression* diff(std::string var) override {
        return new Add(left->diff(var), right->diff(var));
    }

    Expression* copy() override { return new Add(*this); }
};


class Sub: public BinaryOperation {
public:
    Sub(Expression* l, Expression* r) : BinaryOperation(l, r, "-") {}
    Sub(const Sub& other): BinaryOperation(other.left->copy(), other.right->copy(), "-") { }

    Expression* diff(std::string var) override {
        return new Sub(left->diff(var), right->diff(var));
    }

    Expression* copy() override { return new Sub(*this); }
};


class Mult: public BinaryOperation {
public:
    Mult(Expression* l, Expression* r) : BinaryOperation(l, r, "*") {}
    Mult(const Mult& other): BinaryOperation(other.left->copy(), other.right->copy(), "*") { }

    Expression* diff(std::string var) override {
        // (a * b)' = a'*b + a*b'
        return new Add(new Mult(left->diff(var), right->copy()), new Mult(left->copy(), right->diff(var)));
    }

    Expression* copy() override { return new Mult(*this); }
};


class Div: public BinaryOperation {
public:
    Div(Expression* l, Expression* r) : BinaryOperation(l, r, "/") {}
    Div(const Div& other): BinaryOperation(other.left->copy(), other.right->copy(), "/") { }

    Expression* diff(std::string var) override {
        // (a / b)' = (a'*b - a*b') / (b * b)
        return new Div(new Sub(new Mult(left->diff(var), right->copy()), new Mult(left->copy(), right->diff(var))), new Mult(right->copy(), right->copy()));
    }

    Expression* copy() override { return new Div(*this); }
};


class Exponent: public UnaryOperation {
public:
    Exponent(Expression* op) : UnaryOperation(op) {}
    Exponent(const Exponent& other) : UnaryOperation(other.operand->copy()) {}

    Expression* diff(std::string var) override {
        return new Mult(this->copy(), operand->diff(var));
    }

    std::string to_string() const override {
        return "e^" + operand->to_string();
    }

    Expression* copy() override { return new Exponent(*this); }
};