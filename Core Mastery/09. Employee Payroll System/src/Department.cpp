#include "Department.hpp"

Department::~Department() {
    for (Employee* e : employees) {
        delete e;
    }
}

void Department::addEmployee(Employee* employee) {
    employees.push_back(employee);
}

double Department::calculateTotalPayroll() const {
    double total = 0;
    for (const Employee* e : employees) {
        total += e->calculateSalary();
    }
    return total;
}

void Department::printAll() const {
    for (const Employee* e : employees) {
        e->printInfo();
    }
}