#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Shelf.hpp"

class Library {
    private:
        std::vector<std::unique_ptr<Shelf>> shelves;
        std::vector<std::shared_ptr<Author>> authors;

        std::shared_ptr<Author> getOrCreateAuthor(const std::string& name);

    public:
        void addShelf();
        void removeShelf(size_t index);

        void addBook(size_t shelfIndex, int id,
                    const std::string& title,
                    const std::string& authorName);

        Book* findBookByTitle(const std::string& title);
        void removeBookByTitle(const std::string& title);

        void transferBook(const std::string& title,
                        size_t from, size_t to);

        void replaceBook(int id,
                        const std::string& newTitle,
                        const std::string& newAuthor);

        size_t countBooksByAuthor(const std::string& authorName);
};