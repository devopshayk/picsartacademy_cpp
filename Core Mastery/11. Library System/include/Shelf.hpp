#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Book.hpp"

class Shelf {
    private:
        std::vector<std::unique_ptr<Book>> books;

    public:
        void addBook(std::unique_ptr<Book> book);
        Book* findBookByTitle(const std::string& title);
        bool removeBookByTitle(const std::string& title);
        std::unique_ptr<Book> releaseBookByTitle(const std::string& title);
        const std::vector<std::unique_ptr<Book>>& getBooks() const;
};