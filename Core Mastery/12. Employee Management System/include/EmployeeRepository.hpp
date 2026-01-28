#pragma once
#include <vector>
#include <memory>
#include "Employee.hpp"

class EmployeeRepository {
    public:
        void addEmployee(std::shared_ptr<Employee> employee);
        void removeEmployee(int id);

        const std::vector<std::shared_ptr<Employee>>& getAll() const;

    private:
        std::vector<std::shared_ptr<Employee>> employees;
};