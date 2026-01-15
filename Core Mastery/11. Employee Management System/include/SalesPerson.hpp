#pragma once
#include "Employee.hpp"
#include "ISalaried.hpp"
#include <string>

class SalesPerson : public Employee, public ISalaried {
    public:
        SalesPerson(int id, const std::string& name);

        void display() const override;
        double calculateSalary() const override;
};