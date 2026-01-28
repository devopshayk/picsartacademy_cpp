#pragma once
#include <vector>
#include <memory>
#include "Employee.hpp"

class PayrollService {
    public:
        void processPayroll(const std::vector<std::shared_ptr<Employee>>& employees) const;
};