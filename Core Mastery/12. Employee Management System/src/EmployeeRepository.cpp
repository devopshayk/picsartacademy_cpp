#include "EmployeeRepository.hpp"

void EmployeeRepository::addEmployee(std::shared_ptr<Employee> employee) {
    employees.push_back(employee);
}

void EmployeeRepository::removeEmployee(int id) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i]->getId() == id) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}

const std::vector<std::shared_ptr<Employee>>& EmployeeRepository::getAll() const {
    return employees;
}