#include <iostream>
#include <type_traits>

using false_type = std::integral_constant<bool, false>; 
using true_type = std::integral_constant<bool, true>;

// std::conditional rovides member typedef type , which is defined as T if B is true at compile time, or as F if B is false

template <size_t x, size_t y>
struct is_divided: std::conditional_t<x % y == 0, true_type, is_divided<x, y + 1>> { };

template <size_t x>
struct is_divided<x, x>: false_type { };

template <size_t n>
struct is_prime: std::conditional_t<is_divided<n, 2>{}, false_type, true_type> { };

template <size_t n>
struct next_prime: std::conditional_t<is_prime<n>{}, std::integral_constant<size_t, n>, next_prime<n + 1>> { };

template <size_t n>
struct NthPrime: next_prime<NthPrime<n - 1>{} + 1> { };

template <>
struct NthPrime<1>: std::integral_constant<size_t, 2> { };