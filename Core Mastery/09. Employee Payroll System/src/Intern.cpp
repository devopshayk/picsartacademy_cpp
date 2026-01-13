#include "Intern.hpp"

Intern::Intern(const std::string& name, Role role, Employee* mentor, double salary)
    : Employee(name, 0, 0, role),
      mentor(mentor),
      salary(salary) {}

double Intern::calculateSalary() const {
    return salary;
}

void Intern::printInfo() const {
    std::cout << "Intern: " << name
              << ", Mentor: " << mentor->getName()
              << ", Salary: " << calculateSalary()
              << std::endl;
}