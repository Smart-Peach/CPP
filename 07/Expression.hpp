#include <iostream>
#include <string>


class Expression {
    Expression() {}
    virtual ~Expression() {}

    virtual Expression* diff(std::string var) = 0;
    virtual std::string to_string() const = 0;
}