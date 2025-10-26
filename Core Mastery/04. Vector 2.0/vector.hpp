#pragma once
#include <iostream>

class MyVector {
    private:
        int * _data{nullptr};
        size_t _size{};
        size_t _capacity{};

    public:

        // Constructors
        MyVector() : _data(nullptr), _size(0), _capacity(0) {} // or (= default);
        MyVector(size_t initial_capacity); // For capcaity
        MyVector(size_t initial_size, int val); // For size and {unique} elements
        MyVector(std::initializer_list<int> init); // For vector initiliation

        // Destructor
        ~MyVector();

        // Copy & Assignement
        MyVector(const MyVector& other);
        MyVector& operator=(const MyVector& other);

        // Move & Assignement


        // Getters
        size_t getSize() const;
        size_t getCapacity() const;

        // Methods
        void push_back(int element);
        void pop_back();
        void insert(size_t index, int val);
        void insert(size_t index);
        void erase(size_t index);
        void clear();
        void print_vector() const;
};