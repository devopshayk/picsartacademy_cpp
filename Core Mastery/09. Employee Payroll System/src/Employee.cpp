#include "Employee.hpp"

Employee::Employee(const std::string& name, int yearsWorked, int projectsCompleted, Role role)
    : name(name),
      yearsWorked(yearsWorked),
      projectsCompleted(projectsCompleted),
      role(role) {}

Employee::~Employee() {}

const std::string& Employee::getName() const {
    return name;
}