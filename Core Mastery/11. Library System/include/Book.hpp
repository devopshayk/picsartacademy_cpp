#pragma once
#include <string>
#include <memory>

#include "Author.hpp"

class Book {
    private:
        int id;
        std::string title;
        std::shared_ptr<Author> author;

    public:
        Book(int id, const std::string& title, std::shared_ptr<Author> author);

        int getId() const;
        const std::string& getTitle() const;
        std::shared_ptr<Author> getAuthor() const;
};