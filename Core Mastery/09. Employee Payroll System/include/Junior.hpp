#pragma once
#include "Employee.hpp"

class Junior : public Employee {
    private:
        Employee* teamLead;

    public:
        Junior(const std::string& name,
            int projectsCompleted,
            Role role,
            Employee* teamLead);

        double calculateSalary() const override;
        void printInfo() const override;
};