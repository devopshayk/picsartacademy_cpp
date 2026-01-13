#include "Senior.hpp"

Senior::Senior(const std::string& name, int yearsWorked, int projectsCompleted, Role role)
    : Employee(name, yearsWorked, projectsCompleted, role) {}

void Senior::addSubordinate(Employee* employee) {
    subordinates.push_back(employee);
}

double Senior::calculateSalary() const {
    return 2000
         + yearsWorked * 500
         + projectsCompleted * 300
         + subordinates.size() * 400;
}

void Senior::printInfo() const {
    std::cout << "Senior: " << name
              << ", Subordinates: ";

    for (const auto* e : subordinates) {
        std::cout << e->getName() << " ";
    }

    std::cout << ", Salary: " << calculateSalary()
              << std::endl;
}