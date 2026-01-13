#pragma once
#include "Employee.hpp"
#include <vector>

class Department {
    private:
        std::vector<Employee*> employees;

    public:
        ~Department();

        void addEmployee(Employee* employee);
        double calculateTotalPayroll() const;
        void printAll() const;
};
