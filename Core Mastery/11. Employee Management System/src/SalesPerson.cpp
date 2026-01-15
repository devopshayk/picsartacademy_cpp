#include "SalesPerson.hpp"
#include <iostream>

SalesPerson::SalesPerson(int id, const std::string& name)
    : Employee(id, name)
{}

void SalesPerson::display() const {
    std::cout << "SalesPerson: " << name << "ID: " << id << std::endl;
}

double SalesPerson::calculateSalary() const {
    return 4000.0;
}