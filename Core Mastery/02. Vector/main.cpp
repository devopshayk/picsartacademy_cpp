#include <iostream>
#include "vector.hpp"

    int main() {
        MyVector v;
        myvector_init(&v, 5);

        myvector_push_back(&v, 10);
        myvector_push_back(&v, 20);
        myvector_push_back(&v, 30);

        myvector_insert(&v, 1, 99);

        myvector_erase(&v, 2);

        myvector_pop_back(&v);

        myvector_clear(&v);

        myvector_push_back(&v, 10);
        myvector_push_back(&v, 20);
        myvector_push_back(&v, 30);

        myvector_print(&v);

        myvector_destroy(&v);
        
        return 0;
    }