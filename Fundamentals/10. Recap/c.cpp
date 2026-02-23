#include <initializer_list>
#include <stdexcept>
#include <utility>
#include <vector>

template<typename T>
class List
{
private:

    struct Node
    {
        Node* prev;
        Node* next;
        T value;

        Node(const T& v)
            : prev(nullptr), next(nullptr), value(v) {}

        Node(T&& v)
            : prev(nullptr), next(nullptr), value(std::move(v)) {}
    };

    Node* head;
    Node* tail;
    size_t sz;

public:

    List() noexcept
        : head(nullptr), tail(nullptr), sz(0) {}

    ~List()
    {
        clear();
    }

    List(const List& other)
        : List()
    {
        for (Node* n = other.head; n; n = n->next)
            push_back(n->value);
    }

    List(List&& other) noexcept
        : head(other.head),
          tail(other.tail),
          sz(other.sz)
    {
        other.head = nullptr;
        other.tail = nullptr;
        other.sz = 0;
    }

    List(std::initializer_list<T> init)
        : List()
    {
        for (const auto& v : init)
            push_back(v);
    }

    explicit List(const std::vector<T>& vec)
        : List()
    {
        for (const auto& v : vec)
            push_back(v);
    }

    List& operator=(List other)
    {
        swap(other);
        return *this;
    }

    size_t size() const noexcept
    {
        return sz;
    }

    bool empty() const noexcept
    {
        return sz == 0;
    }

    T& front()
    {
        if (!head) throw std::out_of_range("list empty");
        return head->value;
    }

    const T& front() const
    {
        if (!head) throw std::out_of_range("list empty");
        return head->value;
    }

    T& back()
    {
        if (!tail) throw std::out_of_range("list empty");
        return tail->value;
    }

    const T& back() const
    {
        if (!tail) throw std::out_of_range("list empty");
        return tail->value;
    }

    void push_back(const T& value)
    {
        Node* n = new Node(value);

        if (!tail)
            head = tail = n;
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }

        ++sz;
    }

    void push_back(T&& value)
    {
        Node* n = new Node(std::move(value));

        if (!tail)
            head = tail = n;
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }

        ++sz;
    }

    void push_front(const T& value)
    {
        Node* n = new Node(value);

        if (!head)
            head = tail = n;
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }

        ++sz;
    }

    void push_front(T&& value)
    {
        Node* n = new Node(std::move(value));

        if (!head)
            head = tail = n;
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }

        ++sz;
    }

    void pop_back()
    {
        if (!tail) throw std::out_of_range("list empty");

        Node* old = tail;
        tail = tail->prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

        delete old;
        --sz;
    }

    void pop_front()
    {
        if (!head) throw std::out_of_range("list empty");

        Node* old = head;
        head = head->next;

        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete old;
        --sz;
    }

    void insert(size_t pos, const T& value)
    {
        if (pos > sz) throw std::out_of_range("bad index");

        if (pos == 0)
            return push_front(value);

        if (pos == sz)
            return push_back(value);

        Node* cur = head;

        for (size_t i = 0; i < pos; ++i)
            cur = cur->next;

        Node* n = new Node(value);

        n->prev = cur->prev;
        n->next = cur;

        cur->prev->next = n;
        cur->prev = n;

        ++sz;
    }

    void erase(size_t pos)
    {
        if (pos >= sz) throw std::out_of_range("bad index");

        if (pos == 0)
            return pop_front();

        if (pos == sz - 1)
            return pop_back();

        Node* cur = head;

        for (size_t i = 0; i < pos; ++i)
            cur = cur->next;

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        delete cur;
        --sz;
    }

    void clear() noexcept
    {
        Node* cur = head;

        while (cur)
        {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }

        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    void swap(List& other) noexcept
    {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(sz, other.sz);
    }
};