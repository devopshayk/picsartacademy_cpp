#pragma once
#include "Employee.hpp"
#include <string>

class President : public Employee {
    public:
        President(int id, const std::string& name);

        void display() const override;
};