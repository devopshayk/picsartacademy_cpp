#pragma once
#include "Employee.hpp"
#include "ISalaried.hpp"
#include <string>

class Manager : public Employee, public ISalaried {
    public:
        Manager(int id, const std::string& name);

        void display() const override;
        double calculateSalary() const override;
};