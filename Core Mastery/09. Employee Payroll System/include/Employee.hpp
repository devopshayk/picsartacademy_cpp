#pragma once
#include <string>
#include <iostream>

enum class Role {
    QA,
    Designer,
    DevOps,
    SoftwareEngineer,
    SecuritySpecialist,
    ProjectManager
};

class Employee {
    protected:
        std::string name;
        int yearsWorked;
        int projectsCompleted;
        Role role;

    public:
        Employee(const std::string& name,
                int yearsWorked,
                int projectsCompleted,
                Role role);

        virtual ~Employee();

        virtual double calculateSalary() const = 0;
        virtual void printInfo() const = 0;

        const std::string& getName() const;
};