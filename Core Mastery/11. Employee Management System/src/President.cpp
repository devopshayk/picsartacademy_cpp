#include "President.hpp"
#include <iostream>

President::President(int id, const std::string& name)
    : Employee(id, name)
{}

void President::display() const {
    std::cout << "President: " << name << "ID: " << id << std::endl;
}