#pragma once 

#include <iostream>

template <typename Checker, typename... Args>
int getIndexOfTheFirstMatch(Checker checker, Args&&... args) {
    int count = 0;
    int res = -1;
    std::cout << "FUCK" << std::endl;
    // std::forward It determines whether an lvalue reference or an rvalue reference is passed to 
    //it and a reference of the appropriate type is returned
    ((checker(std::forward<Args>(args)) ? res = count : count++), ...);
    return res;
}