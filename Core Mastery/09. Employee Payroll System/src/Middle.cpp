#include "Middle.hpp"

Middle::Middle(const std::string& name, int yearsWorked, int projectsCompleted, Role role, Employee* teamLead)
    : Employee(name, yearsWorked, projectsCompleted, role),
      teamLead(teamLead) {}

double Middle::calculateSalary() const {
    return 1000 + yearsWorked * 300 + projectsCompleted * 200;
}

void Middle::printInfo() const {
    std::cout << "Middle: " << name
              << ", Years: " << yearsWorked
              << ", Projects: " << projectsCompleted
              << ", Team Lead: " << teamLead->getName()
              << ", Salary: " << calculateSalary()
              << std::endl;
}