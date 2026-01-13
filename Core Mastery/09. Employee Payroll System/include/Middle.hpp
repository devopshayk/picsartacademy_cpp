#pragma once
#include "Employee.hpp"

class Middle : public Employee {
    private:
        Employee* teamLead;

    public:
        Middle(const std::string& name,
            int yearsWorked,
            int projectsCompleted,
            Role role,
            Employee* teamLead);

        double calculateSalary() const override;
        void printInfo() const override;
};