#pragma once

template <typename T> class List{
private:
    struct Node {
        Node()= default;

        explicit Node(T value):
            next(nullptr),
            inner(value) {}

        Node(T value, Node* next_node):
            next(next_node),
            inner(value) {}

        ~Node() = default;

        T inner;
        Node* next;
    };

    Node* _head;
    Node* _tail;

public:
    List()= default;

    explicit List(Node* head):
        _head(head) {}

    void push_back(T value) {
        _tail->next = new Node(value);
        _tail = _tail->next;
    }

    void front_back(T value) {
        Node* new_head = new Node(value, _head);
        _head = new_head;
    }

    void push_back_list(List other) {
        _tail->next = other._head;
        _tail = other._tail;
    }

    void push_front_list(List other) {
        other._tail->next = _head;
        _head = other._head;
    }

    T pop_front() {
        T value = _head->inner;
        Node* old_head = _head;
        _head = _head->next;

        delete old_head;
        return value;
    }

    T& get_by_index(int ind) {
        Node* current = _head;
        for(int j = 0; j < ind; j++){
            current = current->next;
        }

        return current->inner;
    }

    T pop_back() {
        Node* current = _head;
        for(; current->next != _tail; current = current->next) {}

        T value = _tail->inner;
        _tail = current;
        delete current->next;
        return value;
    }

    ~List() {
        for(Node* current; current != nullptr; ) {
            Node* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }
};

