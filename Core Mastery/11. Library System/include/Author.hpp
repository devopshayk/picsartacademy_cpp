#pragma once
#include <string>

class Author {
    private:
        std::string name;

    public:
        Author(const std::string& name);
        const std::string& getName() const;
};