#include "PayrollService.hpp"
#include "ISalaried.hpp"
#include <iostream>
#include <type_traits>

void PayrollService::processPayroll(const std::vector<std::shared_ptr<Employee>>& employees) const {
    for (const auto& emp : employees) {
        ISalaried* salaried = dynamic_cast<ISalaried*>(emp.get());
        if (salaried) {
            double salary = salaried->calculateSalary();
            std::cout << emp->getName() << " received salary: $" << salary << std::endl;
        }
    }
}