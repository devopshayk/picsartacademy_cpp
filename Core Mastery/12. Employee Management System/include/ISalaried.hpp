#pragma once

class ISalaried {
    public:
        virtual ~ISalaried() = default;
        virtual double calculateSalary() const = 0;
};