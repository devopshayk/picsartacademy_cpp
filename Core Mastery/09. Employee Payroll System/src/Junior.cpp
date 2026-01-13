#include "Junior.hpp"

Junior::Junior(const std::string& name, int projectsCompleted, Role role, Employee* teamLead)
    : Employee(name, 0, projectsCompleted, role),
      teamLead(teamLead) {}

double Junior::calculateSalary() const {
    return 500 + projectsCompleted * 100;
}

void Junior::printInfo() const {
    std::cout << "Junior: " << name
              << ", Projects: " << projectsCompleted
              << ", Team Lead: " << teamLead->getName()
              << ", Salary: " << calculateSalary()
              << std::endl;
}