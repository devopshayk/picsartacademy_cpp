#include "Developer.hpp"
#include <iostream>

Developer::Developer(int id, const std::string& name)
    : Employee(id, name)
{}

void Developer::display() const {
    std::cout << "Developer: " << name << "ID: " << id << std::endl;
}

double Developer::calculateSalary() const {
    return 5000.0;
}