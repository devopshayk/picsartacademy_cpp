#include "sll.hpp"

// Constructors
SingleList::SingleList() : head(nullptr) {}

SingleList::SingleList(int value, int count) : head(nullptr) {
    for (int i = 0; i < count; ++i) {
        push_back(value);
    }
}

SingleList::SingleList(std::initializer_list<int> init) : head(nullptr) {
    for (int value : init) {
        push_back(value);
    }
}

SingleList::SingleList(const SingleList& other) : head(nullptr) {
    copy(other);
}

SingleList::SingleList(SingleList&& other) noexcept : head(other.head) {
    other.head = nullptr;
}

SingleList::~SingleList() {
    clear();
}

// Assignment Operators
SingleList& SingleList::operator=(const SingleList& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

SingleList& SingleList::operator=(SingleList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

// Operator Overloading
SingleList SingleList::operator+(const SingleList& other) const {
    SingleList result = *this;
    result += other;
    return result;
}

SingleList& SingleList::operator+=(const SingleList& other) {
    Node* curr = other.head;
    while (curr != nullptr) {
        push_back(curr->val);
        curr = curr->next;
    }
    return *this;
}

int& SingleList::operator[](size_t index) {
    Node* curr = head;
    while (index-- && curr != nullptr) {
        curr = curr->next;
    }
    return curr->val;
}

const int& SingleList::operator[](size_t index) const {
    Node* curr = head;
    while (index-- && curr != nullptr) {
        curr = curr->next;
    }
    return curr->val;
}

bool SingleList::operator!() const {
    return head == nullptr;
}

SingleList::operator bool() const {
    return head != nullptr;
}

SingleList& SingleList::operator++() {
    push_back(0);
    return *this;
}

SingleList SingleList::operator++(int) {
    SingleList temp(*this);
    push_back(0);
    return temp;
}

SingleList& SingleList::operator--() {
    pop_back();
    return *this;
}

SingleList SingleList::operator--(int) {
    SingleList temp(*this);
    pop_back();
    return temp;
}

// Friend Operators
bool operator==(const SingleList& lhs, const SingleList& rhs) {
    SingleList::Node* curr1 = lhs.head;
    SingleList::Node* curr2 = rhs.head;

    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->val != curr2->val) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return curr1 == nullptr && curr2 == nullptr;
}

bool operator!=(const SingleList& lhs, const SingleList& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const SingleList& r) {
    os << "[";
    SingleList::Node* curr = r.head;
    while (curr != nullptr) {
        os << curr->val;
        if (curr->next != nullptr) os << ", ";
        curr = curr->next;
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, SingleList& r) {
    r.clear();
    size_t count;
    is >> count;
    while (count--) {
        int value;
        is >> value;
        r.push_back(value);
    }
    return is;
}

// Member Functions
void SingleList::push_front(int value) {
    head = new Node{value, head};
}

void SingleList::push_back(int value) {
    if (head == nullptr) {
        head = new Node{value, nullptr};
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = new Node{value, nullptr};
}

void SingleList::pop_front() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void SingleList::pop_back() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
}

size_t SingleList::size() const {
    size_t count = 0;
    Node* curr = head;
    while (curr != nullptr) {
        ++count;
        curr = curr->next;
    }
    return count;
}

void SingleList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void SingleList::copy(const SingleList& other) {
    Node* curr = other.head;
    while (curr != nullptr) {
        push_back(curr->val);
        curr = curr->next;
    }
}