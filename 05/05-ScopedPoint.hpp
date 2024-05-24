#pragma once

#include <iostream>
#include <optional>

struct Triple { int x; int y; int z; };

template<typename T>
class ScopedPointerCopying {
    T* pointer;

public:

    ScopedPointerCopying(T* raw): pointer(raw) { }
    ScopedPointerCopying(const ScopedPointerCopying& other) { pointer = new T(*other.pointer); }
    ScopedPointerCopying( ScopedPointerCopying&& other) : pointer(other.pointer) { other.pointer = nullptr; }

    ScopedPointerCopying& operator=(ScopedPointerCopying other) {
        if (this != &other) { 
            std::swap(pointer, other.pointer); 
        }
        return *this;
    }
    T& operator*() { return *pointer;}
    const T& operator*() const { return *pointer; }
    T* operator->() { return pointer; }
    const T* operator->() const { return pointer; }

    ~ScopedPointerCopying() { delete pointer; }

    std::optional<T> get() { 
        if (!pointer) return std::nullopt;
        return {*pointer}; 
    }
        
    const std::optional<T> get() const { 
        if (!pointer) return std::nullopt;
        return {*pointer};
    }
};


template<typename T>
class ScopedPointerTransfering {
    T* pointer;

public:

    ScopedPointerTransfering(T* raw): pointer(raw) { }
    ScopedPointerTransfering( ScopedPointerTransfering&& other) : pointer(other.pointer) { other.pointer = nullptr; }
    ScopedPointerTransfering(const ScopedPointerTransfering& other) = delete;

    ScopedPointerTransfering& operator=(ScopedPointerTransfering other) {
        if (this != &other) { 
            std::swap(pointer, other.pointer); 
        }
        return *this;
    }
    T& operator*() { return *pointer;}
    const T& operator*() const { return *pointer; }
    T* operator->() { return pointer; }
    const T* operator->() const { return pointer; }

    std::optional<T> get() { 
        if (!pointer) return std::nullopt;
        return *pointer;
    }
    const std::optional<T> get() const {
        if (!pointer) return std::nullopt; 
        return *pointer; 
    }

    ~ScopedPointerTransfering() { delete pointer; }
};