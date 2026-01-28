#include "EmployeeRepository.hpp"
#include <algorithm>

void EmployeeRepository::addEmployee(std::shared_ptr<Employee> employee) {
    employees.push_back(employee);
}

void EmployeeRepository::removeEmployee(int id) {
    employees.erase(
        std::remove_if(
            employees.begin(),
            employees.end(),
            [id](const std::shared_ptr<Employee>& e) { return e->getId() == id; }
        ),
        employees.end()
    );
}

const std::vector<std::shared_ptr<Employee>>& EmployeeRepository::getAll() const {
    return employees;
}