#include <iostream>
#include "vector.hpp"

    void myvector_init(MyVector* v, size_t capacity) {
        v->capacity = capacity;
        v->data = new int[capacity];
    }

    void myvector_init(MyVector* v, size_t size, int val) {
        v->capacity = v->size = size;
        v->data = new int[v->capacity];

        for(int i = 0; i < size; ++i) v->data[i] = val;
    }

    void myvector_destroy(MyVector* v) {
        v->capacity = 0;
        v->size = 0;
        v->data = nullptr;

        delete[] v->data;
    }

    void myvector_clear(MyVector* v) {
        v->size = 0;
    }

    size_t myvector_size(const MyVector* v) {
        size_t size = v->size;

        return size;
    }

    size_t myvector_capacity(const MyVector* v) {
        size_t capacity = v->capacity;

        return capacity;
    }

    void myvector_push_back(MyVector* v, int value) {
        if(v->size == v->capacity) {
            int * new_array = new int[v->capacity * 2];

            for (int i = 0; i < v->size; ++i) new_array[i] = v->data[i];

            delete v->data;
            v->data = new_array;
            new_array = nullptr;
        }

        v->data[v->size] = value;
        v->size++;
    }

    void myvector_pop_back(MyVector* v) {
        v->data[--v->size] = 0; 
    }

    void myvector_insert(MyVector* v, size_t index, int value) {
        if(index > v->size) return;

        if(v->size == v->capacity) {
            int new_capacity = v->capacity = v->capacity * 2;

            int* new_data = new int[new_capacity];
            for(int i = 0; i < v->size; ++i) new_data[i] = v->data[i];

            delete[] v->data;
            v->data = new_data;
            v->capacity = new_capacity;
        }

        for(int i = v->size; i > index; --i) v->data[i] = v->data[i - 1];

        v->data[index] = value;
        v->size++;
    }

    void myvector_erase(MyVector* v, size_t index) {
        if(index >= v->size) return;

        for(int i = index; i < v->size - 1; i++) v->data[i] = v->data[i + 1];

        --v->size;
    }

    void myvector_print(const MyVector* v) {
        for(int i = 0; i < v->size; i++) std::cout << v->data[i] << std::endl;
    }