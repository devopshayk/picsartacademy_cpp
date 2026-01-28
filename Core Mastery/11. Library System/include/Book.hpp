#pragma once

#include "Author.hpp"


class Book {
    private:
        static int nextId; // in cpp file initilize = 1;
        int bookId{};
        std::string bookTitle;
        Author * bookAth;
    
    public:
        Book() = default;
        Book(std::string title, Author * ath) : bookTitle(title), bookAth(ath), bookId(nextId++) {}
};


// STEPS ---> 1 Author 2. Book 3. Shelf 4. Library 

class Book {
    private:
        static int nextId; // in cpp file initilize = 1;
        int bookId{};
        std::string bookTitle;
        Author * bookAth; // sra texy piti shared ptr lini miangamic asocaciaya kazmakerpum, u funkcia mej tence yndhunum enq hxelov ura vra
    
    public:
        Book() = default;
        Book(std::string title, Author * ath) : bookTitle(title), bookAth(ath), bookId(nextId++) {}
}; // init listum piti arjeqavorenq shared ptrnery, hxelov aftori vra