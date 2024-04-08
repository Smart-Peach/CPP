template<typename T>

class ScopedPointer {
    T* pointer;

public:

    ScopedPointer(T* raw): pointer(raw) { }
    ScopedPointer(const ScopedPointer& other) { 
        pointer = new T(*other.pointer) 
    }

    ScopedPointer( ScopedPointer&& other) : pointer(other.pointer) {
        other.pointer = nullptr;
        }

    T& get() { return *pointer; }
    const T& get() const { return *pointer; }

    ~ScopedPointer() { delete pointer; }
};