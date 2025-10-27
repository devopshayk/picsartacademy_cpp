#pragma once
#include <iostream>

class SingleList {
    private:
        struct Node {
            int val;
            Node* next;

            Node(int value, Node* nextNode = nullptr) : val(value), next(nextNode) {}
        };

        Node* head;

    public:
        
        // Contructos 
        SingleList();                                
        SingleList(size_t count, int value);     
        SingleList(std::initializer_list<int> init);

        // Copy and Move Constructors
        SingleList(const SingleList& other);         
        SingleList(SingleList&& other);

        // Destructor
        ~SingleList();

        // Asignement
        SingleList& operator=(const SingleList& other);  
        SingleList& operator=(SingleList&& other);

        // Getters
        size_t size(int size) const;
        size_t capacity(int capascity) const;

        
};