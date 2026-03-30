#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    template<typename... Args>
    Node(Args&&... args) : data(std::forward<Args>(args)...) {
        next = prev = nullptr;
    }
};


template<typename T>
class List {
    Node<T>* head;
    Node<T>* tail;

    public:
        List() : head(nullptr), tail(nullptr) {}
        ~List() {
            Node<T>* current = head;
            while(current) {
                Node<T>* tmp = current->next;
                delete current;
                current = tmp;
            }
        }

        template<typename... Args>
        void emplace_back(Args&&... args) {
            Node<T>* node = new Node<T>(std::forward<Args>(args)...);
            if (!tail) {
                head = tail = node;
            } else {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }

        template<typename... Args>
        void emplace_front(Args&&... args) {
            Node<T>* node = new Node<T>(std::forward<Args>(args)...);
            if (!head) {
                head = tail = node;
            } else {
                node->next = head;
                head->prev = node;
                head = node;
            }
        }

        template<typename... Args>
        void emplace(Node<T>* pos, Args&&... args) {
            if (!pos) {
                emplace_back(std::forward<Args>(args)...);
                return;
            }

            Node<T>* node = new Node<T>(std::forward<Args>(args)...);
            node->prev = pos->prev;
            node->next = pos;

            if (pos->prev) pos->prev->next = node;
            pos->prev = node;

            if (head == pos) head = node;
        }

        void print() const {
            Node<T>* current = head;
            while(current) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << "\n";
        }

        Node<T>* get_head() const { return head; }
        Node<T>* get_tail() const { return tail; }
};

struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

int main() {
    List<Point> lst;

    lst.emplace_back(1,2);

    lst.emplace_front(3,4);

    lst.emplace_back(5,6);

    lst.emplace(lst.get_head()->next, 7,8);

    lst.print();

    return 0;
}