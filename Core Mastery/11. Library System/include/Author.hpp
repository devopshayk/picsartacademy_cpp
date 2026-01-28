#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <exception>


class Author {
    private:
        std::string nameAuthor;

    public:
        Author() = default;
        Author(std::string name) : nameAuthor(name) {} 
};