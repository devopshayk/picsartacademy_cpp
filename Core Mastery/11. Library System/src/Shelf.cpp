#include "Shelf.hpp"
#include "Book.hpp"

void Shelf::addBook(std::unique_ptr<Book> book) {
    books.push_back(std::move(book));
}

Book* Shelf::findBookByTitle(const std::string& title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i]->getTitle() == title) {
            return books[i].get();
        }
    }
    return nullptr;
}

bool Shelf::removeBookByTitle(const std::string& title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i]->getTitle() == title) {
            books.erase(books.begin() + i);
            return true;
        }
    }
    return false;
}

std::unique_ptr<Book> Shelf::releaseBookByTitle(const std::string& title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i]->getTitle() == title) {
            std::unique_ptr<Book> result = std::move(books[i]);
            books.erase(books.begin() + i);
            return result;
        }
    }
    return std::unique_ptr<Book>(nullptr);
}

const std::vector<std::unique_ptr<Book>>& Shelf::getBooks() const {
    return books;
}
