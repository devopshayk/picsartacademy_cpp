#include "Manager.hpp"
#include <iostream>

Manager::Manager(int id, const std::string& name)
    : Employee(id, name)
{}

void Manager::display() const {
    std::cout << "Manager: " << name << "ID: " << id << std::endl;
}

double Manager::calculateSalary() const {
    return 6000.0;
}