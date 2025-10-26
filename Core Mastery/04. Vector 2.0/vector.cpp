#include "vector.hpp"
#include <iostream>

MyVector::MyVector(size_t initial_capacity) 
    : _size{},
    _capacity(initial_capacity)
{
    if(_capacity > 0) {
        _data = new int[_capacity];
    } else {
        _data = nullptr;
    }
}

MyVector::MyVector(size_t initial_size, int val) 
    : _size(initial_size),
    _capacity(initial_size),
    _data(nullptr)
{
    if(_capacity > 0) {
        _data = new int[_capacity];

        for(size_t i{}; i < _size; ++i) {
            _data[i] = val;
        }
    }
}

MyVector::MyVector(std::initializer_list<int> init) 
    : _size{},
    _capacity(init.size()),
    _data(nullptr)
{
    if(_capacity > 0) {
        _data = new int[init.size()];

        for(int val : init) {
            _data[_size++] = val;
        } 
    }
}

MyVector::~MyVector() {
    delete[] _data;
}

// --> Ctors And Dtors <--

MyVector::MyVector(const MyVector& other)
    : _size(other._size),
    _capacity(other._capacity),
    _data(nullptr)
{
    if(_capacity > 0) {
        _data = new int[_capacity];

        for(size_t i{}; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
}

MyVector& MyVector::operator=(const MyVector& other) {
    if(this == &other) return *this;

    delete[] _data;

    _size = other._size;
    _capacity = other._capacity;

    if(_capacity > 0) {
        _data = new int[_capacity];

        for(size_t i{}; i < _size; i++) {
            _data[i] = other._data[i];
        }
    } else {
        _data = nullptr;
    }

    return *this;
}

// --> Setters <--
size_t MyVector::getSize() const { return _size; }
size_t MyVector::getCapacity() const { return _capacity; }

