#pragma once
#include <iostream>
#include <initializer_list>


template <typename T>
class DLL {
    private:
        struct Node {
            T value;
            Node * next;
            Node * prev;
        };

        Node * head;
        Node * laid;

    public:
        DLL() = default;
        DLL(T val) : value(val), next(nullptr), prev(nullptr) {};
        DLL(std::initializer_list<T> init);
};

// template<typename Container, typename Index>
// auto get(Container& c, Index i) { return c[i]; }

// auto foo() {
//     return {1, 2};
// }