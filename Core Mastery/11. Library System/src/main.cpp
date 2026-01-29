#include <iostream>
#include "Library.hpp"

int main() {
    Library lib;

    std::cout << "Add shelves\n";
    lib.addShelf();
    lib.addShelf();

    std::cout << "Add books\n";
    lib.addBook(0, 1, "Book A", "Author One");
    lib.addBook(0, 2, "Book B", "Author One");   // тот же автор
    lib.addBook(1, 3, "Book C", "Author Two");

    std::cout << "\nFind book\n";
    Book* b = lib.findBookByTitle("Book B");
    if (b != nullptr) {
        std::cout << "Found: " << b->getTitle()
                  << ", author: " << b->getAuthor()->getName() << "\n";
    }

    std::cout << "\nCount books by Author One\n";
    std::cout << lib.countBooksByAuthor("Author One") << "\n";

    std::cout << "\nTransfer Book B from shelf 0 to shelf 1\n";
    lib.transferBook("Book B", 0, 1);

    std::cout << "Check transfer\n";
    if (lib.findBookByTitle("Book B") != nullptr) {
        std::cout << "Book B exists after transfer\n";
    }

    std::cout << "\nReplace Book C (new edition)\n";
    lib.replaceBook(3, "Book C - New Edition", "Author One");

    std::cout << "Check replaced book\n";
    Book* c = lib.findBookByTitle("Book C - New Edition");
    if (c != nullptr) {
        std::cout << "Replaced: " << c->getTitle()
                  << ", author: " << c->getAuthor()->getName() << "\n";
    }

    std::cout << "\nCount books by Author One after replace\n";
    std::cout << lib.countBooksByAuthor("Author One") << "\n";

    std::cout << "\nRemove Book A\n";
    lib.removeBookByTitle("Book A");

    if (lib.findBookByTitle("Book A") == nullptr) {
        std::cout << "Book A successfully removed\n";
    }

    std::cout << "\nRemove shelf 0 (all books on it destroyed)\n";
    lib.removeShelf(0);

    std::cout << "\nFinal count Author One\n";
    std::cout << lib.countBooksByAuthor("Author One") << "\n";

    std::cout << "\nProgram finished successfully\n";
    return 0;
}
