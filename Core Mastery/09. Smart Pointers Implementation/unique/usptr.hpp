#pragma once

template <typename T>
class uniqe_ptr {
private:
    T* ptr;

public:
    uniqe_ptr() : ptr(nullptr) {}
    uniqe_ptr(T* p) : ptr(p) {}

     Destructor
    ~uniqe_ptr() { delete ptr; }

    uniqe_ptr(const uniqe_ptr&) = delete;
    uniqe_ptr& operator=(const uniqe_ptr&) = delete;

    uniqe_ptr(uniqe_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    uniqe_ptr& operator=(uniqe_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }

    
    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T* p) {
        delete ptr;
        ptr = p;
    }

    void swap(uniqe_ptr& other) noexcept {
        std::swap(ptr, other.ptr);
    }
};