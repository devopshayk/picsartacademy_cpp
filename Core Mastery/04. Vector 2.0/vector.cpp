#include "vector.hpp"
#include <iostream>

// Constructors
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
    : _size{initial_size},
    _capacity{initial_size},
    _data{nullptr}
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
    _capacity{init.size()},
    _data{nullptr}
{
    if(_capacity > 0) {
        _data = new int[init.size()];

        for(int val : init) {
            _data[_size++] = val;
        } 
    }
}


// Destructor and Clear Method
MyVector::~MyVector() {
    _size = 0;
    _capacity = 0;

    delete[] _data;
}

void MyVector::clear() { _size = 0; }


// Copy Constructor & Copy Assignement Operator
MyVector::MyVector(const MyVector& other)
    : _size{other._size},
    _capacity{other._capacity},
    _data{nullptr}
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


// Move Constructor & Move Assignement Operator
MyVector::MyVector(MyVector&& other) noexcept
    :_size{other._size},
    _capacity{other._capacity},
    _data{other._data}
{
    other._size = 0;
    other._capacity = 0;
    other._data = nullptr;
}

MyVector& MyVector::operator=(MyVector&& other) noexcept {
    if(this == &other) return *this;
    
    delete[] _data;

    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;

    other._data = nullptr;
    other._size = 0;
    other._capacity = 0;

    return *this;
}


// Getters 
size_t MyVector::getSize() const { return _size; }
size_t MyVector::getCapacity() const { return _capacity; }


// Methods
void MyVector::push_back(int element) {
    if(_size == _capacity) {
        size_t new_capacity = _capacity * 2;
        int * new_data = new int[new_capacity];
        
        for(size_t i{}; i < _size; ++i) new_data[i] = _data[i];

        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;

        new_data = nullptr;
    }

    _data[_size++] = element;
}

void MyVector::pop_back() {
    if(_size) _data[--_size];
    else std::cout << "Vector is empty" << std::endl;
}

void MyVector::insert(size_t index, int val) {
    if(index >= _size || index < 0) {
        std::cout << "Not valid index, write " << 0 << " >" << " and " << _size << "< index" << std::endl;
        return;
    }

    if(_size == _capacity) {
        int new_capacity = _capacity * 2;
        
        int* new_data = new int[new_capacity];
        for(size_t i = 0; i < _size; ++i) new_data[i] = _data[i];
        
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;

        new_data = nullptr;
    }

    for(size_t i = _size; i > index; --i) _data[i] = _data[i - 1];

    _data[index] = val;
    _size++;
}

void MyVector::insert(size_t index) {
    if(index >= _size || index < 0) {
        std::cout << "Not valid index, write " << 0 << " >" << " and " << _size << "< index" << std::endl;
        return;
    }

    if(_size == _capacity) {
        int new_capacity = _capacity * 2;
        int* new_data = new int[new_capacity];

        for(size_t i = 0; i < _size; ++i) new_data[i] = _data[i];
        
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;

        new_data = nullptr;
    }

    for(size_t i = _size; i > index; --i) _data[i] = _data[i - 1];

    _data[index] = 0;
    _size++;
}

void MyVector::erase(size_t index) {
    if(index >= _size) {
        std::cout << "Not valid index, write " << 0 << " >" << " and " << _size << "< index" << std::endl;
        return;
    }

    if(_size == _capacity) {
        int new_capacity = _capacity * 2;
        int * new_data = new int[new_capacity];

        for(int i{}; i < _size; ++i) new_data[i] = _data[i];

        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;

        new_data = nullptr;
    }

    for(int i = index; i < _size; ++i) { 
        _data[i] = _data[i + 1];
    }

    _data[_size--];
}

void MyVector::print_vector() const {
    for(size_t i{}; i < _size; ++i) std::cout << _data[i] << ", ";
    std::cout << std::endl; 
}