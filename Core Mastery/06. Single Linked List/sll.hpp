#pragma once
#include <iostream>

class SingleList {
    private:
        struct Node {
            int val;
            Node* next;
        };

        Node* head;

    public:

        // Constructors & Destructor
        SingleList();                               
        SingleList(int value, int count);           
        SingleList(std::initializer_list<int> init);
        SingleList(const SingleList& other);        
        SingleList(SingleList&& other) noexcept;    
        ~SingleList();                              

        // Assignment Operators
        SingleList& operator=(const SingleList& other);   
        SingleList& operator=(SingleList&& other) noexcept; 

        // Operator Overloading
        SingleList operator+(const SingleList& other) const;
        SingleList& operator+=(const SingleList& other);
        int& operator[](size_t index);
        const int& operator[](size_t index) const;
        bool operator!() const;
        explicit operator bool() const;

        SingleList& operator++();       
        SingleList operator++(int);     
        SingleList& operator--();      
        SingleList operator--(int);    

        // Friend Operators
        friend bool operator==(const SingleList& lhs, const SingleList& rhs); 
        friend bool operator!=(const SingleList& lhs, const SingleList& rhs); 
        friend std::ostream& operator<<(std::ostream& os, const SingleList& r);
        friend std::istream& operator>>(std::istream& is, SingleList& r);

        // Member Functions
        void push_front(int value);
        void push_back(int value);
        void pop_front();
        void pop_back();
        size_t size() const;
        void clear();
        void copy(const SingleList& other);
};