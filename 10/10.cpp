#include <iostream>
#include <exception>


template<typename Derived, size_t MaxInstances>
class Limit {
    static inline int objects_alive = 0;

public:
    Limit() {
        if (objects_alive >= MaxInstances) {
            throw std::out_of_range("Too many instances!");
        } else ++objects_alive;
    }

    Limit(const Limit&) {
        if (objects_alive >= MaxInstances) {
            throw std::out_of_range("Too many instances!");
        } else ++objects_alive;
    }

    ~Limit() {
        --objects_alive;
    }
};

class Something: public Limit<Something, 3> {
    void print() {
        std::cout << "hello" << std::endl;
    }
};

class Everything: public Limit<Something, 5> {
    void print() {
        std::cout << "hello" << std::endl;
    }
};

