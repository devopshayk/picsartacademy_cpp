#include <iostream>
#include "vector.hpp"

void myvector_init(MyVector* v, size_t capacity) {
    v -> capacity = capacity;
    v -> size = 0;
    v -> data = new int[capacity];
}

void myvector_init(MyVector* v, size_t size, int val) {
    v -> capacity = v -> size = size;
    v -> data = new int[v -> capacity];

    for(size_t i = 0; i < size; ++i) v -> data[i] = val;
}

void myvector_destroy(MyVector* v) {
    v -> capacity = 0;
    v -> size = 0;
    delete[] v -> data;
    
    v -> data = nullptr;
}

void myvector_clear(MyVector* v) {
    v -> size = 0;
}

size_t myvector_size(const MyVector* v) {
    return v -> size;
}

size_t myvector_capacity(const MyVector* v) {
    return v -> capacity;
}

void myvector_push_back(MyVector* v, int value) {
    if(v -> size == v -> capacity) {
        size_t new_capacity = v -> capacity * 2;
        int * new_array = new int[new_capacity];

        for (size_t i = 0; i < v -> size; ++i) new_array[i] = v -> data[i];

        delete[] v -> data;
        v -> data = new_array;
        v -> capacity = new_capacity;
        new_array = nullptr;
    }

    v -> data[v -> size] = value;
    v -> size++;
}

void myvector_pop_back(MyVector* v) {
    if(v -> size > 0) {
        --v -> size; 
    } else {
        std::cout << "Vector is empty" << std::endl;
    }
}

void myvector_insert(MyVector* v, size_t index, int value) {
    if(index >= v -> size) return;
    if(index < 0) std::cout << "Enter positive index (0 >= index)" << std::endl;

    if(v -> size == v -> capacity) {
        int new_capacity = v -> capacity * 2;

        int* new_data = new int[new_capacity];
        for(size_t i = 0; i < v -> size; ++i) new_data[i] = v -> data[i];
        
        delete[] v -> data;
        v -> data = new_data;
        v -> capacity = new_capacity;
    }

    for(size_t i = v -> size; i > index; --i) v -> data[i] = v -> data[i - 1];

    v -> data[index] = value;
    v -> size++;
}

void myvector_erase(MyVector* v, size_t index) {
    if(index >= v -> size) return;
    if(index < 0) std::cout << "Enter positive index (0 >= index)" << std::endl;

    for(size_t i = index; i < v -> size - 1; i++) v -> data[i] = v -> data[i + 1];

    --v -> size;
}

void myvector_print(const MyVector* v) {
    for(size_t i = 0; i < v -> size; i++) { std::cout <<  v -> data[i] << " " ; }
    std::cout << std::endl;
}