#pragma once

#include "../14/14.hpp"
#include <iostream>
#include <vector>
#include <type_traits>
#include <utility>  


typedef char byte;

template<typename... Types>
constexpr size_t get_size = (sizeof(Types) + ...);

template<typename... Types>
class Container {
    byte* start_pointer;
    std::vector<size_t> shifts;
    size_t general_shift = 0;

    template<typename T>
    void add_type_shift() {
        shifts.push_back(general_shift);
        general_shift += sizeof(T);
    }

    template<typename T>
    void free_type(size_t& ind) { (*((T*) (start_pointer + shifts[ind++]))).~T(); }

public:
    Container(Types... types) {
        start_pointer = new byte[get_size<Types...>];
        allocate<get_size<Types...>>(start_pointer, std::forward<Types>(types)...); // nstt 14 allocator

        (add_type_shift<Types>(), ...);
    }

    template<typename T>
    T& getElement(size_t ind) { return *((T*) (start_pointer + shifts[ind])); }

    ~Container() {
        size_t ind = 0;
        (free_type<Types>(ind), ...);
        delete[] start_pointer;  
    }
};