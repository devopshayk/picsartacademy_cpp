#include "Employee.hpp"

Employee::Employee(int id, const std::string& name)
    : id(id), name(name)
{
}

int Employee::getId() const {
    return id;
}

const std::string& Employee::getName() const {
    return name;
}