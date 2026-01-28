#include "Accountant.hpp"
#include <iostream>

Accountant::Accountant(int id, const std::string& name)
    : Employee(id, name)
{
}

void Accountant::display() const {
    std::cout << "Accountant: " << name << "ID: " << id << std::endl;
}

double Accountant::calculateSalary() const {
    return 4500.0;
}