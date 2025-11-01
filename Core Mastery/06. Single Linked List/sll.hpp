#pragma once
#include <iostream>

class SingleList {
    private:
        struct Node {
            int val;
            Node * next;
        };

        Node * head;

    public:        

        // Constructors & Destructor
        SingleList() : head(nullptr)  {}
        SingleList(int value, int count);
        SingleList(std::initializer_list<int> value);
        SingleList(const SingleList& other);
        SingleList(SingleList&& other) noexcept;

        // Assignement Operators
        SingleList& operator=(const SingleList& other);
        SingleList& operator=(SingleList&& other);

        // Operator Overloading
        SingleList operator+() const;
        SingleList& operator+=(const SingleList& oth);
        friend bool operator==(const SingleList& lhs, const SingleList& rhs); 
        friend bool operator!=(const SingleList& lhs, const SingleList& rhs); 
        // []
        friend std::istream& operator>>(std::istream& is, SingleList& r);
        friend std::ostream& operator<<(std::ostream& os, const SingleList& r);
        SingleList& operator++();
        SingleList& operator--();
        SingleList operator++(int);
        SingleList operator--(int);
};


// <-------- To Be Continued ----------->