#include "Author.hpp"

Author::Author(const std::string& name) : name(name) {}

const std::string& Author::getName() const {
    return name;
}