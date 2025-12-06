#pragma once

template <typename T>
class shared_ptr {
    private:
        T* ptr;
        size_t* count;

        void release_current() {
            if (count) {
                --(*count);
                if (*count == 0) {
                    delete ptr;
                    delete count;
                }
            }
            
            ptr = nullptr;
            count = nullptr;
        }

    public:
        shared_ptr() : ptr(nullptr), count(nullptr) {}
        explicit shared_ptr(T* p) : ptr(p), count(new size_t(1)) {}

        shared_ptr(const shared_ptr& other) : ptr(other.ptr), count(other.count) {
            if (count) ++(*count);
        }

        shared_ptr(shared_ptr&& other) noexcept : ptr(other.ptr), count(other.count) {
            other.ptr = nullptr;
            other.count = nullptr;
        }

        shared_ptr& operator=(const shared_ptr& other) {
            if (this != &other) {
                release_current();
                ptr = other.ptr;
                count = other.count;
                if (count) ++(*count);
            }
            return *this;
        }

        shared_ptr& operator=(shared_ptr&& other) noexcept {
            if (this != &other) {
                release_current();
                ptr = other.ptr;
                count = other.count;
                other.ptr = nullptr;
                other.count = nullptr;
            }
            return *this;
        }

        ~shared_ptr() {
            release_current();
        }

        T* get() const { return ptr; }
        T& operator*() const { return *ptr; }
        T* operator->() const { return ptr; }
        size_t use_count() const { return count ? *count : 0; }
        bool unique() const { return use_count() == 1; }
        explicit operator bool() const { return ptr != nullptr; }

        void reset(T* p = nullptr) {
            release_current();
            if (p) {
                ptr = p;
                count = new size_t(1);
            }
        }

        void swap(shared_ptr& other) noexcept {
            std::swap(ptr, other.ptr);
            std::swap(count, other.count);
        }
};
