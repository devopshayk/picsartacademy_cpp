#pragma once 
#include <iostream>
#include <string>

class Employee {
    public:
        Employee(int id, const std::string& name);
        virtual ~Employee() = default;

        virtual void display() const = 0;

        int getId() const;
        const std::string& getName() const;

    protected:
        int id;
        std::string name;
};