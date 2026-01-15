#pragma once
#include "Employee.hpp"
#include "ISalaried.hpp"
#include <string>

class Developer : public Employee, public ISalaried {
    public:
        Developer(int id, const std::string& name);

        void display() const override;
        double calculateSalary() const override;
};