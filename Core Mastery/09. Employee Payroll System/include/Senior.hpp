#pragma once
#include "Employee.hpp"
#include <vector>

class Senior : public Employee {
    private:
        std::vector<Employee*> subordinates;

    public:
        Senior(const std::string& name,
            int yearsWorked,
            int projectsCompleted,
            Role role);

        void addSubordinate(Employee* employee);

        double calculateSalary() const override;
        void printInfo() const override;
};