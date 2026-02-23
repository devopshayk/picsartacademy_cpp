#include <iostream>

template<typename T>
class List {
    private:
        struct Node {
            T value;
            Node* next;
            Node* prev;

            Node(const T& v = T())
                : value(v), next(nullptr), prev(nullptr) {}
        };

        Node* sentinel;
        size_t sz;

    public:

        class iterator {
            Node* node;

            public:

                iterator(Node* n) : node(n) {}

                T& operator*() {
                    return node->value;
                }

                iterator& operator++() {
                    node = node->next;
                    return *this;
                }

                iterator& operator--() {
                    node = node->prev;
                    return *this;
                }

                bool operator==(const iterator& other) const {
                    return node == other.node;
                }

                bool operator!=(const iterator& other) const {
                    return node != other.node;
                }

                friend class List;
            };


        public:

            List()
            {
                sentinel = new Node;

                sentinel->next = sentinel;
                sentinel->prev = sentinel;

                sz = 0;
            }

            ~List()
            {
                clear();
                delete sentinel;
            }


            bool empty() const
            {
                return sz == 0;
            }


            size_t size() const
            {
                return sz;
            }


            iterator begin() {
                return iterator(sentinel->next);
            }


            iterator end() {
                return iterator(sentinel);
            }


            void push_back(const T& value) {
                insert(end(), value);
            }


            void push_front(const T& value) {
                insert(begin(), value);
            }


            iterator insert(iterator pos, const T& value) {
                Node* current = pos.node;

                Node* newNode = new Node(value);
            
                newNode->next = current;
                newNode->prev = current->prev;

                current->prev->next = newNode;
                current->prev = newNode;

                ++sz;

                return iterator(newNode);
            }


            iterator erase(iterator pos) {
                Node* node = pos.node;

                if (node == sentinel)
                    return end();

                iterator ret(node->next);

                node->prev->next = node->next;
                node->next->prev = node->prev;

                delete node;

                --sz;

                return ret;
            }


            void pop_back() {
                erase(--end());
            }


            void pop_front() {
                erase(begin());
            }

            void clear()
            {
                Node* current = sentinel->next;

                while (current != sentinel)
                {
                    Node* next = current->next;
                    delete current;
                    current = next;
                }

                sentinel->next = sentinel;
                sentinel->prev = sentinel;

                sz = 0;
            }
};