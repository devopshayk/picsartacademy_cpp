#include "Developer.hpp"
#include "SalesPerson.hpp"
#include "EmployeeRepository.hpp"
#include "PayrollService.hpp"
#include <memory>
#include <iostream>

int main() {
    EmployeeRepository repository;
    PayrollService payroll;

    auto dev1 = std::make_shared<Developer>(1, "Alice");
    auto dev2 = std::make_shared<Developer>(2, "Bob");
    auto sales1 = std::make_shared<SalesPerson>(3, "Charlie");

    repository.addEmployee(dev1);
    repository.addEmployee(dev2);
    repository.addEmployee(sales1);

    // Выводим всех сотрудников
    std::cout << "--- All Employees ---" << std::endl;
    for (const auto& emp : repository.getAll()) {
        emp->display();
    }

    // Выплата зарплаты
    std::cout << "\n--- Payroll ---" << std::endl;
    payroll.processPayroll(repository.getAll());

    return 0;
}