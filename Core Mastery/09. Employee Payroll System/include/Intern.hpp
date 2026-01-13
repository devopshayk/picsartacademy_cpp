#pragma once
#include "Employee.hpp"

class Intern : public Employee {
    private:
        Employee* mentor;
        double salary;

    public:
        Intern(const std::string& name,
            Role role,
            Employee* mentor,
            double salary);

        double calculateSalary() const override;
        void printInfo() const override;
};
