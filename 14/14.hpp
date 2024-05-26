#include <iostream>
#include <type_traits>


template<typename... Types>
constexpr bool copy_check = (std::is_copy_constructible_v<Types> && ...);

template<typename... Types>
constexpr bool memory_check(int size) { return size >= (sizeof(Types) + ...); }

template<typename T>
constexpr char* _allocate(char* ptr, T&& arg) {
    new(ptr) std::remove_reference_t<T>(std::forward<T>(arg));
    ptr += sizeof(T);
    return ptr;
}

template<int SIZE, typename... Types>
void allocate(void* memory, Types&&... types) requires (memory_check<Types...>(SIZE) && copy_check<Types...>) {
    char* current_ptr = static_cast<char*>(memory);
    ((current_ptr = _allocate(current_ptr, std::forward<Types>(types))), ...);
}