#include "Library.hpp"
#include "Book.hpp"

std::shared_ptr<Author> Library::getOrCreateAuthor(const std::string& name) {
    for (size_t i = 0; i < authors.size(); ++i) {
        if (authors[i]->getName() == name) {
            return authors[i];
        }
    }

    std::shared_ptr<Author> author(new Author(name));
    authors.push_back(author);
    return author;
}

void Library::addShelf() {
    shelves.push_back(std::unique_ptr<Shelf>(new Shelf()));
}

void Library::removeShelf(size_t index) {
    if (index < shelves.size()) {
        shelves.erase(shelves.begin() + index);
    }
}

void Library::addBook(size_t shelfIndex, int id, const std::string& title, const std::string& authorName) {
    if (shelfIndex >= shelves.size()) {
        return;
    }

    std::shared_ptr<Author> author = getOrCreateAuthor(authorName);
    std::unique_ptr<Book> book(new Book(id, title, author));
    shelves[shelfIndex]->addBook(std::move(book));
}

Book* Library::findBookByTitle(const std::string& title) {
    for (size_t i = 0; i < shelves.size(); ++i) {
        Book* b = shelves[i]->findBookByTitle(title);
        if (b != nullptr) {
            return b;
        }
    }
    return nullptr;
}

void Library::removeBookByTitle(const std::string& title) {
    for (size_t i = 0; i < shelves.size(); ++i) {
        if (shelves[i]->removeBookByTitle(title)) {
            return;
        }
    }
}

void Library::transferBook(const std::string& title, size_t from, size_t to) {
    if (from >= shelves.size() || to >= shelves.size()) {
        return;
    }

    std::unique_ptr<Book> book = shelves[from]->releaseBookByTitle(title);
    if (book != nullptr) {
        shelves[to]->addBook(std::move(book));
    }
}

void Library::replaceBook(int id, const std::string& newTitle, const std::string& newAuthor) {
    for (size_t i = 0; i < shelves.size(); ++i) {
        std::vector<std::unique_ptr<Book>>& books =
            const_cast<std::vector<std::unique_ptr<Book>>&>(
                shelves[i]->getBooks()
            );

        for (size_t j = 0; j < books.size(); ++j) {
            if (books[j]->getId() == id) {
                std::shared_ptr<Author> author =
                    getOrCreateAuthor(newAuthor);

                books[j].reset(new Book(id, newTitle, author));
                return;
            }
        }
    }
}

size_t Library::countBooksByAuthor(const std::string& authorName) {
    size_t count = 0;

    for (size_t i = 0; i < shelves.size(); ++i) {
        const std::vector<std::unique_ptr<Book>>& books =
            shelves[i]->getBooks();

        for (size_t j = 0; j < books.size(); ++j) {
            if (books[j]->getAuthor()->getName() == authorName) {
                ++count;
            }
        }
    }

    return count;
}