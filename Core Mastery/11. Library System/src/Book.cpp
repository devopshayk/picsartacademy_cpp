#include "Book.hpp"

Book::Book(int id, const std::string& title, std::shared_ptr<Author> author)
    : id(id), title(title), author(std::move(author)) {}

int Book::getId() const {
    return id;
}

const std::string& Book::getTitle() const {
    return title;
}

std::shared_ptr<Author> Book::getAuthor() const {
    return author;
}